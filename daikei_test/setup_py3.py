from setuptools import setup, Extension

__auhtor__ = 'Takayuki Suzuki'
__version__ = '0.0'

requires = [
]

module = Extension('daikei_test',
                   sources=['daikei_testmodule_py3.c',
                            'src/main.c',
                            'src/func_test.c',
                            'src/minimum.c'],
                   include_dirs=['src'])

setup(name='Daikei Test',
      version='0.0',
      description='c ext sample daikei_test',
      author=__auhtor__,
      author_email='sample@mail.com',
      url='http://sample/url.html',
      long_description='''
daikei integral.
''',
      ext_modules=[module])

