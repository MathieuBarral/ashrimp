.PHONY: all
all:
	@mkdir -p build
	@cmake -B build/ -DCMAKE_GENERATOR=Ninja && cmake --build build/
.PHONY: debug
debug:
	@mkdir -p build
	@cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_GENERATOR=Ninja -B build/ && cmake --build build/

.PHONY: test
test:
	@ninja -C build/ coverage || (echo "Use 'make debug' to generate CTest files")

.PHONY: cov
cov:
	@open build/coverage/index.html || (echo "Use 'make test' to generate Gcovr files")

.PHONY: re
re:
	@cmake --build build/

.PHONY: clean
clean:
	@rm -rf build/

.PHONY: fclean
fclean: clean
