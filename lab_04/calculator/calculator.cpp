#include <QtWidgets>
#include <cmath>

#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent): QMainWindow(parent) {
	setWindowRole("pop-up");
	ui = new Ui::Calculator;
	ui->setupUi(this);

	ui->lhs->setValidator(new QDoubleValidator(this));
	ui->rhs->setValidator(new QDoubleValidator(this));

	clear();

	foreach(QAbstractButton * btn, ui->inputGroup->buttons()) {
		connect(btn, &QAbstractButton::clicked, this, &Calculator::insertText);
	}

	foreach(QAbstractButton * btn, ui->operationGroup->buttons()) {
		connect(btn, &QAbstractButton::clicked, this, &Calculator::setOperation);
	}

	connect(ui->btnDelete, &QAbstractButton::clicked, this, &Calculator::deleteText);
	connect(ui->btnClear, &QAbstractButton::clicked, this, &Calculator::clear);
	connect(ui->btnEquals, &QAbstractButton::clicked, this, &Calculator::calculate);
}

Calculator::~Calculator() {
	delete activeInput;
	delete ui;
}

void Calculator::calculate() {
	double lhs = ui->lhs->text().toDouble();
	double rhs = ui->rhs->text().toDouble();
	QLCDNumber *result = ui->result;
	switch (operation) {
		case Operation::ADD:
			result->display(lhs + rhs);
			break;
		case Operation::SUBTRACT:
			result->display(lhs - rhs);
			break;
		case Operation::MULTIPLY:
			result->display(lhs * rhs);
			break;
		case Operation::DIVIDE:
			result->display(lhs / rhs);
			break;
		case Operation::SQRT:
			result->display(std::sqrt(lhs));
		default:
			return;
	}
}

void Calculator::clear() {
	ui->lhs->clear();
	setOperation();
	ui->rhs->clear();
	ui->result->display(0);
	activeInput = ui->lhs;
}

void Calculator::deleteText() {
	activeInput->backspace();
}

void Calculator::insertText() {
	QPushButton *btn = qobject_cast<QPushButton*>(sender());
	if (btn) {
		activeInput->insert(btn->text());
	}
}

void Calculator::setOperation() {
	QPushButton *btn = qobject_cast<QPushButton*>(sender());
	QString op = btn ? btn->text() : "__";
	bool carryOp = true;
	if (op == "+") {
		operation = Operation::ADD;
	}
	else if (op == "÷") {
		operation = Operation::DIVIDE;
	}
	else if (op == "×") {
		operation = Operation::MULTIPLY;
	}
	else if (op == "√") {
		operation = Operation::SQRT;
		carryOp = false;
	}
	else if (op == "-") {
		operation = Operation::SUBTRACT;
	}
	else {
		op = "__";
		carryOp = false;
		operation = Operation::NONE;
	}
	ui->operationText->setText(op);

	if (activeInput == ui->rhs && carryOp && ui->result->value()) {
		ui->lhs->setText(QString::number(ui->result->value()));
		ui->rhs->clear();
	}

	if (op == "√") {
		ui->rhs->hide();
	}
	else {
		ui->rhs->show();
		activeInput = ui->rhs;
	}
}
