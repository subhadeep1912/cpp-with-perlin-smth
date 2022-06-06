#include "utils.h"
#include <cmath>
#include "ppm.h"
#include "PerlinNoise.h"
#include <array>


int main()
{
    std::vector<float> vertices;

    PerlinNoise pn(237);

    for(float i=0.0f;i<5;i += 1.0f)
    {
        static int k=0;
        for(float j=0.0f;j<5;j+=1.0f)
        {   
            static int l=0;
            // std::cout<<i<<j<<"\n";
            vertices.push_back(j);
            vertices.push_back(10*pn.noise(10*i, 10*j, 0.8));
            vertices.push_back(i);
            l++;
        }
        k++;
    }

    std::vector<float> br;
    for(int i =0;i<100;i++)
    {
        float lon = i*M_PI*2/100;
        for(int j=0;j<100;j++)
        {
            float lat = j*M_PI/100;
            float x = 200*sin(lon)*cos(lat);
            float y = 200*sin(lon)*sin(lat);
            float z = 200* cos(lon);
            br.push_back(x);
            br.push_back(y);
            br.push_back(z);
        }
    }


    
    std::vector<int> indices;

    // int k=0;
    // for(int i=0;i<98;i++)
    // {
        
    //     indices.push_back(k);
    //     indices.push_back(k+1);
    //     indices.push_back(k+2);
    //     k++;
        
    // }






    // std::cout<<vertices.size()<<"\n";
    // for(int i=0;i<vertices.size();i++)
    // {
    //     std::cout<<vertices[i]<<"\n";
    // }   
    // int var = 5;
    // for(int j=0;j<var;j++)
    // {
    //     for(int i=0;i<var;i++)
    //     {   
    //         if(i==var-1 || j==var-1)
    //             break;
    //         indices.push_back(var*j+i);
    //         indices.push_back(var*(j+1)+i);
    //         indices.push_back(var*(j+1)+i+1);

    //         indices.push_back(var*j+i);
    //         indices.push_back(var*(j+1)+i+1);
    //         indices.push_back(var*j+i+1);
    //     }
    // }
    for(auto &i:vertices)
        std::cout<<i<<"\n";

    return 0;
}