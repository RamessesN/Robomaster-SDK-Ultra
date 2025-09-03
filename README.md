# Robomaster-SDK-Ultra

---

### Description: 
Rewrite the `robomaster` library to make it compatible with the later version of Python.

---

### Notice:
- `media` module has been overwritten by `PyAV`, which is used to encode `H264` video
- `python-version`: ( `3.6.6`, `3.11.0` )

---

### Robomaster-SDK-Ultra Usage:
1. run `git clone git@github.com:RamessesN/Robomaster-SDK-Ultra.git` to download
2. set `lib` files to `Sources Root` to make it can be found globally
3. start your `xxx.py` with `from robomaster_ultra import xxx`
4. Details of the api Usage: See [robomaster documentaton](https://robomaster-dev.readthedocs.io/zh-cn/latest/index.html)

---

### TODO:
1. fix `audioop` deprecation in python3.11 from [`camera.py`](robomaster_lib/robomaster_ultra/camera.py)
   > See [audioop](https://docs.python.org/3/library/audioop.html)
2. fix audio loss caused by transfer from `libmedia_codec` to `pyav`

---

#### ⚠️ License: The project isn't open source. See details [LICENSE](./LICENSE).

---

#### @ author: [RamessesN](https://github.com/RamessesN)
#### @ date: 2025-09-03