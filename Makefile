build:
	$(CC) main.c -o sysdbd -lcrossdb -lpthread -g

run: all
	./sysdbd

install: all
	@mkdir -p /sonic-ng/bin
	install -c sysdbd /sonic-ng/bin/
