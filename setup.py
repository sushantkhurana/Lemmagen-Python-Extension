#Created by Sushant Khurana (sushant@sukh.us)

from distutils.core import setup, Extension

_module = Extension('pylemmatize',
                    sources = ['expose_to_python.cpp'])

setup (name = 'pylemmatize',
       version = '1.0',
       description = 'Lemmatizes the current string over Leximes, exposed Python API for LemmaGen',
       ext_modules = [_module])
