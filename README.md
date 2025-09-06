# Robomaster-SDK-Ultra

---

### Description: 
Rewrite the **robomaster** library to make it compatible with the later version of Python

---

### Notice:
- It includes `libmedia_codec` for media decoding / encoding support (H264 / Opus).
- Python Compatibility: `3.7` ~ `3.13`

---

### Robomaster-SDK-Ultra Usage:
1. clone to local
2. **robomaster-sdk-ultra** depends on `ffmpeg` and `opus` libraries. Install them via `homebrew` or system package manager
    - macOS (Apple Silicon / Intel): `brew install ffmpeg@4 opus`
    - Linux (Ubuntu / Debian): `sudo apt update; sudo apt install ffmpeg libopus-dev`
3. install **robomaster sdk ultra** library:
   - `cd Robomaster-SDK-Ultra`
   - `pip install -e .`
4. install **media decoder** dependency: 
   - `cd robomaster_lib/libmedia_codec_ultra`
   - `pip install -e .`
5. install **pybind11** dependency:
   - `cd pybind11`
   - `pip install -e .`
6. start your `xxx.py` with `from robomaster_ultra import xxx`
7. details of the api usage: Reference - [robomaster documentaton](https://robomaster-dev.readthedocs.io/zh-cn/latest/index.html)

---

### TODO:
1. ...

---

#### ⚠️ License: The project isn't open source. See details [LICENSE](./LICENSE).

---

#### @ author: [RamessesN](https://github.com/RamessesN)
#### @ date: 2025-09-06