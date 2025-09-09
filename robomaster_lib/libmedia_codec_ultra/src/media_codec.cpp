#include "media_codec_ultra.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

PYBIND11_MODULE(libmedia_codec_ultra, m) {
    py::class_<PyH264Decoder>(m, "H264Decoder")
        .def(py::init<std::string, bool>(),
             py::arg("output_format") = "BGR",
             py::arg("verbose") = false)

        // 绑定 decode 方法，同时支持 bytes/str
        .def("decode", [](PyH264Decoder &self, py::object input) {
            if (py::isinstance<py::bytes>(input)) {
                return self.decode(input.cast<py::bytes>());
            } else if (py::isinstance<py::str>(input)) {
                // 自动把 str 转成 bytes 再解码
                auto b = py::bytes(input);
                return self.decode(b);
            } else {
                throw std::runtime_error("decode() expects bytes or str");
            }
        });

    py::class_<PyOpusDecoder>(m, "OpusDecoder")
        .def(py::init<int, int, int>(),
             py::arg("frame_size") = 960,
             py::arg("sample_rate") = 48000,
             py::arg("channels") = 1)

        // 绑定 decode 方法，同时支持 bytes/str
        .def("decode", [](PyOpusDecoder &self, py::object input) {
            if (py::isinstance<py::bytes>(input)) {
                return self.decode(input.cast<py::bytes>());
            } else if (py::isinstance<py::str>(input)) {
                auto b = py::bytes(input);
                return self.decode(b);
            } else {
                throw std::runtime_error("decode() expects bytes or str");
            }
        });
}
