import sys
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
project_root = os.path.dirname(current_dir)
lib_path = os.path.join(project_root, 'lib')

if lib_path not in sys.path:
    sys.path.insert(0, lib_path)