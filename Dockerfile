FROM gcc:8.2.0
COPY . /usr/src/program
WORKDIR /usr/src/program
RUN make
CMD ["./bin/main"]
