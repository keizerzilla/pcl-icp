# pcl_icp.cpp
Um programa simples que executa o ICP implemetado pela biblioteca PCL.

## Dependências (testado no Ubuntu 18.04+)
```
sudo apt update
sudo apt install libpcl-* -y
```

## Compilando
```
cmake .
make
```

## Usando
```
./pcl_icp <src>.ply <tgt>.ply <reg>.ply
```
