# Robomaster-SDK-Ultra

![docs](https://img.shields.io/badge/docs-passing-brightgreen)
![docs](https://img.shields.io/badge/docs-stable-brightgreen)
![latest version](https://img.shields.io/badge/latest%20version-v1.2.0-darkblue)
![compatible sys](https://img.shields.io/badge/compatible%20sys-macOS%20|%20Linux-yellow) \
![python](https://img.shields.io/badge/python-3.8%20|%203.9%20|%203.10%20|%203.11%20|%203.12%20|%203.13-blue)

---

### Description: 
Rewrite the **robomaster** library to make it compatible with the later version of Python

---

### Notice:
- It includes `libmedia_codec_ultra` for media decoding / encoding support (H264 / Opus).
- Python Compatibility: `3.7` ~ `3.13`

---

### Robomaster-SDK-Ultra Installation:

<details open>
<summary> install by automator-script </summary>

1. clone to local
2. `cd Robomaster-SDK-Ultra`
3. `sudo chmod 755 ./installer.sh`
4. `./installer.sh`

</details>

<details>
<summary> Manual Installation </summary>

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

</details>

---

### Test Installation:

1. start your `xxx.py` with `from robomaster_ultra import xxx`
2. details of the api-usage: Reference - [robomaster documentaton](https://robomaster-dev.readthedocs.io/zh-cn/latest/index.html)

---

### TODO:

1. Port into `Windows` system (Crazy Difficult)
2. ...

---

#### ⚠️ License: The project isn't open source. See details [LICENSE](./LICENSE).

---

#### @ author: [RamessesN](https://github.com/RamessesN)
#### @ date: 2025-09-07