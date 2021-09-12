mkdir ./doc/img
cp ./sphinx/* ./src/
cp ./sphinx/img/* ./doc/img/
sphinx-build -b html ./src ./doc