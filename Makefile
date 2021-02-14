define colorecho
	@tput setaf 2
	@echo $1
	@tput sgr0
endef
CFLAGS0   = -Wall -Wextra -mtune=native -no-pie
CFLAGS   = -Wall -Wextra -mtune=native -no-pie `sdl2-config --cflags`
CFLAGS1  = -Wall -Wextra -mtune=native -no-pie `sdl-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_gfx -lm
LDFLAGS1 = `sdl-config --libs` -lSDL_image -lm
LDFLAGS0 = -lm
TARGETS = 5 1 2 3 4 6 7 8

.PHONY: all
all: $(TARGETS)

dummy: dummy.c 
	@cc $(CFLAGS) -o $@ $< $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

1:   helper.c  1.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

2:   helper.c  2.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

3:   helper.c  3.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

4:   helper.c  4.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

5:   helper.c  5.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

sine_wave:   sine_wave.c
	@cc $(CFLAGS0) -o $@ $+ $(LDFLAGS0)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

6:   helper.c  6.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

7:   helper.c  7.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

8:   helper2.c  8.c
	@cc $(CFLAGS) -o $@ $+ $(LDFLAGS)
	$(call colorecho,"$@ success. ./\"$@\" to execute.")

.PHONY: clean
clean:
	@rm $(TARGETS) 2>/dev/null || true
	$(call colorecho,"It is clean now.")

#$<	die erste Abhängigkeit
#$@	Name des targets
#$+	eine Liste aller Abhängigkeiten
#$^	eine Liste aller Abhängigkeiten,
#	wobei allerdings doppelt vorkommende Abhängigkeiten eliminiert wurden.

# while inotifywait -e close_write ./anim.c; do date +%X; make > /dev/null; done
