#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "Updating pip..."
pip install --upgrade pip

# Check Homebrew
if ! command -v brew &> /dev/null; then
    echo "Homebrew not found. Please install Homebrew first: https://brew.sh/"
    exit 1
fi

# Install ffmpeg@4
echo "Installing ffmpeg@4..."
brew install ffmpeg@4

# Adjust PATH
if [[ $(uname -m) == "arm64" ]]; then
    export PATH="/opt/homebrew/opt/ffmpeg@4/bin:$PATH"
else
    export PATH="/usr/local/opt/ffmpeg@4/bin:$PATH"
fi

echo "Installing robomaster_ultra..."
pip install -e .

echo "Installing libmedia_codec_ultra..."
pip install -e ./robomaster_lib/libmedia_codec_ultra

echo "Installing pybind11..."
pip install -e ./robomaster_lib/libmedia_codec_ultra/pybind11

echo "Done!"