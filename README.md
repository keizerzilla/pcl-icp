# pcl_icp.cpp
Um programa simples que executa o ICP implemetado pela biblioteca PCL.

## Dependências (testado no Ubuntu 18.04+)
```
sudo apt update
sudo apt install libpcl-* -y
```

## Compilando
```
git clone https://github.com/keizerzilla/pcl-icp
cd pcl-icp/
cmake .
make
```

## Usando
```
./pcl_icp <src>.ply <tgt>.ply <reg>.ply
```

- `<src>.ply`: nuvem de entrada (_source_)
- `<tgt>.ply`: nuvem alvo (_target_)
- `<reg>.ply`: nuvem com resultado do registro (_registered_, _aligned_)
- `.ply`: formato de nuvem de pontos criado pela Stanford ([Wikipedia](https://en.wikipedia.org/wiki/PLY_(file_format)))
