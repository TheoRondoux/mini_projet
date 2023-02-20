CC= g++
src = $(wildcard *.cpp) #collects all source files in the current directory in the src variable.
obj = $(src:.c=.o) #transforms the contents of the src variable, changing all file suffixes from .c to .o, thus constructing the object file list we need.
LDFLAGS = # for the list of libraries required during linking

hero_vs_monsters: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean # PHONY its target is not an actual file that will be generated

clean: #rule for cleaning up every target
	rm -f $(obj) hero_vs_monsters
