from setuptools import setup, Extension

__auhtor__ = 'Takayuki Suzuki'
__version__ = '0.0'

requires = [
]

module = Extension('study_dl',
                   sources=['study_dl_module.c',
                            'src/step_function.c'],
                   include_dirs=['src'])

setup(name='Study DeepLearning',
      version='0.0',
      description='c ext sample daikei_test',
      author=__auhtor__,
      author_email='sample@mail.com',
      url='http://sample/url.html',
      long_description='''
study code of deep learning.
''',
      ext_modules=[module])

