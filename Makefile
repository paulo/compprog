.PHONY: cpp-new rust-new cpp-compile rust-compile cpp-test rust-test

CXXFLAGS=-std=c++0x
CXXPLUGSFLAGS=-Wall -Wextra -Werror -Wpedantic -pedantic-errors
OPTIMIZATION=-O2
WORKINGDIR=wip
TEMPLATEDIR=templates

help: ## Show this help
	@echo "Help"
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "    \033[36m%-20s\033[93m %s\n", $$1, $$2}'

cpp-new: ## Start new problem with given name with a cpp template
	@mkdir -p $(WORKINGDIR)/$(t)/test
	@mkdir -p $(WORKINGDIR)/$(t)/bin
	@cp $(TEMPLATEDIR)/.cpp $(WORKINGDIR)/$(t)/$(t).cpp
	@touch $(WORKINGDIR)/$(t)/test/test.txt

rust-new: ## Start new problem with given name with a rust template
	@mkdir -p $(WORKINGDIR)/$(t)/test
	@mkdir -p $(WORKINGDIR)/$(t)/bin
	@cp $(TEMPLATEDIR)/.rs $(WORKINGDIR)/$(t)/$(t).rs
	@touch $(WORKINGDIR)/$(t)/test/test.txt

cpp-compile: $(WORKINGDIR)/$(t)/$(t).cpp ## Compile with g++
	@mkdir -p $(WORKINGDIR)/$(t)/bin
	@g++ $(CXXFLAGS) $(WORKINGDIR)/$(t)/$(t).cpp -o $(WORKINGDIR)/$(t)/bin/$(t)

rust-compile: $(WORKINGDIR)/$(t)/$(t).rs ## Compile with rustc
	@rustc $(WORKINGDIR)/$(t)/$(t).rs -o $(WORKINGDIR)/$(t)/bin/$(t)

exec: ## Execute the binary
	@./$(WORKINGDIR)/$(t)/bin/$(t)

cpp-test: cpp-compile ## Compile with g++ and test
	@cat $(WORKINGDIR)/$(t)/test/test.txt | ./$(WORKINGDIR)/$(t)/bin/$(t)

rust-test: rust-compile ## Compile with rustc and test
	@cat $(WORKINGDIR)/$(t)/test/test.txt | ./$(WORKINGDIR)/$(t)/bin/$(t)
