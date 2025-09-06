from setuptools import setup, find_packages

setup(
    name = "robomaster-sdk-ultra",
    version = "1.2.0",
    author = "RamessesN",
    description = "Later Python Compatible Robomaster SDK",
    packages = find_packages(where = "robomaster_lib"),
    package_dir = {"": "robomaster_lib"},
    python_requires = ">=3.7",
    install_requires = [
        "netifaces>=0.11.0",
        "netaddr>=1.3.0",
        "scipy>=1.15.0"
    ]
)