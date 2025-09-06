#!/bin/bash
set -e

cd "$(dirname "$0")"

echo "Updating pip..."
pip install --upgrade pip

echo "Installing robomaster_ultra..."
pip install -e .

echo "Installing libmedia_codec_ultra..."
pip install -e ./robomaster_lib/libmedia_codec_ultra

echo "Installing pybind11..."
pip install -e ./robomaster_lib/libmedia_codec_ultra/pybind11

echo "Done!"