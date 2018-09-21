#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
	class Calculator;
}

class QLineEdit;

enum class Operation {
	NONE,
	ADD,
	DIVIDE,
	MULTIPLY,
	SQRT,
	SUBTRACT,
};

class Calculator: public QMainWindow {
	Q_OBJECT

	public:
		explicit Calculator(QWidget *parent = 0);
		~Calculator();

	private:
		Ui::Calculator *ui;
		QLineEdit *activeInput;
		Operation operation = Operation::NONE;

	private slots:
		void calculate();
		void clear();
		void deleteText();
		void insertText();
		void setOperation();
};

#endif
