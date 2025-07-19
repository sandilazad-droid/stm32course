# Use a base image with Ubuntu
FROM ubuntu:20.04

# Set environment variables to ensure non-interactive apt installation
ENV DEBIAN_FRONTEND=noninteractive

# Install basic dependencies and utilities
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    wget \
    curl \
    gdb-multiarch \
    python3 \
    python3-pip \
    make \
    sudo \
    unzip \
    libnewlib-arm-none-eabi \
    && apt-get clean

# Install ARM GCC Toolchain
RUN wget https://developer.arm.com/-/media/Files/downloads/gnu-toolchain/gnu-rm/11.2-2021.11/bin/arm-none-eabi-gcc-11.2-2021.11-x86_64-linux.tar.xz && \
    tar -xf arm-none-eabi-gcc-11.2-2021.11-x86_64-linux.tar.xz && \
    mv arm-none-eabi-gcc-11.2-2021.11-x86_64-linux /opt/ && \
    ln -s /opt/arm-none-eabi-gcc-11.2-2021.11-x86_64-linux/bin/arm-none-eabi-* /usr/local/bin/

# Install OpenOCD for debugging
RUN apt-get update && apt-get install -y openocd

# Install STM32CubeMX (Java-based application)
RUN apt-get install -y default-jre && \
    wget https://www.st.com/content/ccc/resource/technical/software/firmware/embedded-software/stm32cube/stm32cube-mx/stm32cubemx/latest-release/stm32cubemx_setup_v5-5-0.linux -O /tmp/stm32cubemx_setup.sh && \
    chmod +x /tmp/stm32cubemx_setup.sh && \
    /tmp/stm32cubemx_setup.sh -q

# Install other useful tools
RUN apt-get update && apt-get install -y \
    ninja-build \
    libtool \
    automake \
    autoconf \
    pkg-config

# Set up working directory for project files
WORKDIR /workspace

# Expose the STM32 project port (optional)
EXPOSE 8080

# Set the entrypoint to start a shell
ENTRYPOINT [ "/bin/bash" ]
