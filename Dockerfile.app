FROM gcc:latest

RUN apt-get update && apt-get install -y \
    cmake \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

RUN mkdir -p build && cd build \
    && cmake .. \
    && make

CMD ["/bin/sh", "-c", "/app/build/testproj && tail -f /dev/null"]


