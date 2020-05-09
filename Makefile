FLAGS = -pedantic-errors -std=c++11

word_art.o: word_art.cpp word_art.h
	g++ $(FLAGS) -c $<

main_game.o: main_game.cpp errands.h battle.h shop.h character.h
	g++ $(FLAGS) -c $<

main_game: main_game.o word_art.o
	g++ $(FLAGS) $^ -o @

clean:
	rm -f main_game.o word_art.o 

.PHONY: clean