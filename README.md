# Robomaster-SDK-Ultra

---

### Description: 
Rewrite the `robomaster` library to make it compatible with the later version of Python.

---

### Notice:
- It includes `libmedia_codec` for media decoding/encoding support (H264/Opus).
- `python-version`: `3.7` ~ `3.11`

---

### Robomaster-SDK-Ultra Usage:
1. `git clone git@github.com:RamessesN/Robomaster-SDK-Ultra.git`
2. The SDK depends on `ffmpeg` and `opus` libraries. Install them via `homebrew` or system package manager
    - macOS (Apple Silicon / Intel): `brew install ffmpeg@4 opus`
    - Linux (Ubuntu / Debian): `sudo apt update; sudo apt install ffmpeg libopus-dev`
3. `cd Robomaster-SDK-Ultra` and then `pip install -e .`
4. start your `xxx.py` with `from robomaster_ultra import xxx`
5. details of the api usage: See [robomaster documentaton](https://robomaster-dev.readthedocs.io/zh-cn/latest/index.html)

---

### TODO:
1. fix `audioop` deprecation in python3.11 from [`camera.py`](robomaster_lib/robomaster_ultra/camera.py)
   - Reference [audioop](https://docs.python.org/3/library/audioop.html)

---

#### ⚠️ License: The project isn't open source. See details [LICENSE](./LICENSE).

---

#### @ author: [RamessesN](https://github.com/RamessesN)
#### @ date: 2025-09-05