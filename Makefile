UBDIR=ubuild/

all:
	mkdir -p $(UBDIR)
	g++ boxlang.cpp -o $(UBDIR)boxlang
