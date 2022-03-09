/**
 * pcl_icp: Programa simples que registra duas nuvens de pontos usando PCL.
 */

#include <time.h>
#include <string>
#include <iostream>
#include <pcl/io/ply_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

int pcl_registration(int argc, char *argv[])
{
    PointCloudT::Ptr cloud_source(new PointCloudT);
    PointCloudT::Ptr cloud_target(new PointCloudT);
    PointCloudT::Ptr cloud_registered(new PointCloudT);
    
    pcl::io::loadPLYFile(argv[1], *cloud_source);
    pcl::io::loadPLYFile(argv[2], *cloud_target);
    
    double epsilon = 0.00001;
    int max_iter = 20;
    pcl::IterativeClosestPoint<PointT, PointT> icp;
    
    icp.setTransformationEpsilon(epsilon);
    icp.setMaximumIterations(max_iter);
    icp.setInputSource(cloud_source);
    icp.setInputTarget(cloud_target);
    icp.align(*cloud_registered);
    
    pcl::io::savePLYFile(argv[3], *cloud_registered);
    
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        printf("ERRO! Número errado de argumentos de programa!\n");
        printf("USO:  %s <src>.ply <tgt>.ply <reg>.ply\n", argv[0]);
        return -1;
    }
    
    clock_t start;
	clock_t end;
    
    start = clock();
    pcl_registration(argc, argv);
    end = clock();
    
	printf("%s:\t%lu cycles\n", argv[0], end - start);
    
    return 0;
}
