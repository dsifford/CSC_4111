SHELL = /bin/sh

bindir = bin

targets += $(patsubst %.uml, bin/%.png, $(wildcard *.uml))
targets += $(patsubst %.md, bin/%.pdf, $(wildcard *.md))

.PHONY: all
all: installdirs main

.PHONY: installdirs
installdirs: 
	@ mkdir -p $(bindir)
	@ rm -f $(bindir)/*

main: $(targets)

$(bindir)/%.png: %.uml
	@ cat $< | docker run --rm -i think/plantuml -tpng > $@ 

$(bindir)/%.pdf: %.md
	@ pandoc --highlight-style breezedark -V geometry:landscape -f markdown_github+escaped_line_breaks -t latex -o $@ $<
