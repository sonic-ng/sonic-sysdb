build:
	$(CC) main.c -o sysdbd -lcrossdb -lpthread -g

run: build
	./sysdbd

install: build
	@mkdir -p /sonic-ng/bin
	install -c sysdbd /sonic-ng/bin/
