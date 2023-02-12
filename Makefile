.DEFAULT_GOAL := run
SRC_TARGET := vector_test.cpp
OUTPUT_FILE := vector_test.out

raytrace: 
	@echo "Compiling Ray_Trace.cpp"
	g++ -o ./Ray_Trace.out ./Ray_Trace.cpp
	@echo "Running Ray_Trace.out"
	./Ray_Trace.out

run: $(FILE)
	@echo "Compiling "$(SRC_TARGET)
	g++ -o ./$(OUTPUT_FILE) ./$(SRC_TARGET)
	@echo "Running "$(OUTPUT_FILE)
	./$(OUTPUT_FILE)

clean:
	@rm ./Ray_Trace.out