from setuptools import find_packages
from setuptools import setup

setup(
    name='ros2_pubsub',
    version='0.0.0',
    packages=find_packages(
        include=('ros2_pubsub', 'ros2_pubsub.*')),
)
