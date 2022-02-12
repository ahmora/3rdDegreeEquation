CC = g++
#CFLAGS = -lboost_system -lboost_filesyste
TARGET = findroots

compile: src/ecuaciones.cpp lib/Equation.hpp
	$(CC) src/ecuaciones.cpp -o $(TARGET).o #(CFLAGS)

clean: $(TARGET).o 
	rm $(TARGET).o
	rm -r src/*~ lib/*~

run: $(TARGET).o
	./$(TARGET).o 1 1 1 1


test: $(TARGET).o
	@echo "Case a=1, b=1, c=1, d=1. Discriminant expected= 16. Roots expected: {-1}"
	./$(TARGET).o 1 1 1 1
	@echo "Case a=1, b=-2, c=-5, d=6. Discriminant expected= 900 Roots expected: {-2,1,3}"
	./$(TARGET).o 1 -2 -5 6
	@echo "Case a=1, b=-3, c=4, d=-2. Discriminant expected= -4 Roots expected: {1}"
	./$(TARGET).o 1 -3 4 -2
	@echo "Case a=1, b=-4, c=6, d=-24. Discriminant expected= -11616 Roots expected: {4}"
	./$(TARGET).o 1 -4 6 -24
	@echo "Case a=3, b=1, c=1, d=16. Discriminant expected= -61419 Roots expected: {-1.7979}"
	./$(TARGET).o 3 1 1 16
	@echo "Case a=1, b=-3, c=4, d=-6. Discriminant expected= -436 Roots expected: {2.3788}"
	./$(TARGET).o 1 -3 4 -6
	@echo "Case a=1, b=-5, c=8, d=-4. Discriminant expected=0 Roots expected: {1,2}"
	./$(TARGET).o 1 -5 8 -4

