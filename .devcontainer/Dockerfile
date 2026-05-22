FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make \
    libgoogle-glog-dev \
    gdb \
    git \
    clang-format-18 \
    libfreetype-dev \
    libx11-dev \
    libxrandr-dev \
    libxcursor-dev \
    libxi-dev \
    libudev-dev \
    libgl1-mesa-dev \
    libflac-dev \
    libogg-dev \
    libvorbis-dev \
    libopenal-dev \
    libmbedtls-dev \
    libssh2-1-dev \
    libharfbuzz-dev \
    && rm -rf /var/lib/apt/lists/*
        
# SFML
ARG SFML_VERSION=3.1.0
RUN git clone --depth 1 --branch ${SFML_VERSION} https://github.com/SFML/SFML.git /tmp/sfml \
    && cmake -S /tmp/sfml -B /tmp/sfml/build \
        -DCMAKE_BUILD_TYPE=Release \
        -DBUILD_SHARED_LIBS=ON \
        -DSFML_BUILD_EXAMPLES=OFF \
        -DSFML_BUILD_DOC=OFF \
    && cmake --build /tmp/sfml/build -j$(nproc) \
    && cmake --install /tmp/sfml/build \
    && rm -rf /tmp/sfml \
    && ldconfig