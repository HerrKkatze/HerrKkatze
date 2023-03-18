#include <iostream>
#include <fstream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include<stb/stb_image.h>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Matrix.h"



using namespace std;
using namespace glm;


const unsigned int width = 800;
const unsigned int height = 600;

GLfloat vertices[] =
{ 
    /*-0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
    -0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
     0.5f, 0.0f, -0.5f,     0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
     0.5f, 0.0f,  0.5f,     0.83f, 0.70f, 0.44f,	5.0f, 0.0f,
     0.0f, 0.8f,  0.0f,     0.92f, 0.86f, 0.76f,	2.5f, 5.0f*/

    /*-1.0f,-1.0f,-1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    -1.0f,1.0f,-1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    1.0f,1.0f,-1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    1.0f,-1.0f,-1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,

    -1.0f,-1.0f,1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    -1.0f,1.0f,1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    1.0f,1.0f,1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,
    1.0f,-1.0f,1.0f,     0.83f, 0.70f, 0.44f, 0.0f, 0.0f,*/



     -1.0f,1.0f,-1.0f, 0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
     -1.0f,-1.0f,-1.0f,0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
     1.0f,-1.0f,-1.0f,0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
     1.0f,1.0f,-1.0f,0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

     -1.0f,1.0f,1.0f,0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
     -1.0f,-1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
     1.0f,-1.0f,1.0f,0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
     1.0f,1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

                1.0f,1.0f,-1.0f,0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
                1.0f,-1.0f,-1.0f,0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
                1.0f,-1.0f,1.0f,0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
                1.0f,1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

                -1.0f,1.0f,-1.0f,0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
                -1.0f,-1.0f,-1.0f,0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
                -1.0f,-1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
                -1.0f,1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

                -1.0f,1.0f,1.0f,0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
                -1.0f,1.0f,-1.0f,0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
                1.0f,1.0f,-1.0f,0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
                1.0f,1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 1.0f,

                -1.0f,-1.0f,1.0f,0.83f, 0.70f, 0.44f,	0.0f, 0.0f,
                -1.0f,-1.0f,-1.0f,0.83f, 0.70f, 0.44f,	0.0f, 1.0f,
                1.0f,-1.0f,-1.0f,0.83f, 0.70f, 0.44f,	1.0f, 0.0f,
                1.0f,-1.0f,1.0f,0.83f, 0.70f, 0.44f,	1.0f, 1.0f,
};


GLuint indices[] =
{
    /*0, 1, 2,
    0, 2, 3,
    0, 1, 4,
    1, 2, 4,
    2, 3, 4,
    3, 0, 4*/

    /*0,1,2,
    2,0,3,
    4,5,6,
    4,6,7,*/

    0,1,3,
                3,1,2,
                4,5,7,
                7,5,6,
                8,9,11,
                11,9,10,
                12,13,15,
                15,13,14,
                16,17,19,
                19,17,18,
                20,21,23,
                23,21,22
};

int main()
{
    
    
    glfwInit();
    

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    

    GLFWwindow* window = glfwCreateWindow(width, height, "create", NULL, NULL);

    if (window == NULL)
    {
        std::cout << "Failed to create Window";
        glfwTerminate();
        return -1;

    }
    

    glfwMakeContextCurrent(window);

    gladLoadGL();
    
    


    glViewport(0, 0, width, height);


    Shader shaderProgram("mainVertex.glsl","mainFragment.glsl");

    


    VAO VAO1;

    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));


    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    


    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();
    


    GLuint unitID = glGetUniformLocation (shaderProgram.ID, "scale");


    int widthImg, heightImg, numColCh;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* bytes = stbi_load("cat_head_anime.jpg", &widthImg, &heightImg, &numColCh, 0);


    unsigned int texture;
    glGenTextures(1, &texture);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthImg, heightImg, 0, GL_RGB, GL_UNSIGNED_BYTE, bytes);
    glGenerateMipmap(GL_TEXTURE_2D);


    stbi_image_free(bytes);
    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint tex0 = glGetUniformLocation(shaderProgram.ID, "tex0");




    
    

    
    

    


    


    
    

    float sinusaid = 0.0f;
    shaderProgram.Activate();
    glUniform1i(tex0, 0);

    //glEnable(GL_DEPTH_TEST);
    //glDepthFunc(GL_ALWAYS);
    
    //glDepthMask(GL_FALSE);
    double prevTime = glfwGetTime();
    MATRIX MATRIXTrans;
    MATRIX MATRIXprojectionMatrixold;


    MATRIX MATRIXprojectionMatrix;

    MATRIXprojectionMatrix.nulling();

    MATRIX ViewMatrix;
    ViewMatrix.nulling();
    //ViewMatrix.translete(Vector(0.0f, 1.0f, 0.0f));

    #pragma region Region_1
    mat4 vie = mat4(1.0f);
    vie =  translate(vie, vec3(0.0f, -0.5f, -2.0f));

    mat4 modele = mat4(1.0f);
    //vie = mat4(1.0f);



    //modele = rotate(modele, radians(3.0f), vec3(0.0f, 1.0f, 0.0f));
    //modele = glm::translate(modele, vec3(0.0f, 1.0f, 0.0f));
    /*cout << endl;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << modele[i][j] << "     ";
        }
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << vie[i][j] << "     ";
        }
        cout << endl;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << ViewMatrix.MAX[i][j] << "     ";
        }
        cout << endl;
    }*/
    




    

    

    #pragma endregion Region_1
    
    glEnable(GL_DEPTH_TEST);
    
    
    
    while (!glfwWindowShouldClose(window)) {
        //glEnable(GL_DEPTH_TEST);
        
        
        
        glClearColor(1, 0, 0, 1);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        shaderProgram.Activate();

        double crntTime = glfwGetTime();
        if (crntTime - prevTime >= 1/30 )
        {
            sinusaid += 0.00f;
            double prevTime = crntTime;
        }
        #pragma region excess

        mat4 modele = mat4(1.0f);
        vie = mat4(1.0f);
        mat4 proj = mat4(1.0f);

        proj = perspective(radians(90.0f), (GLfloat)(width / height),  0.01f, 100.0f);
        proj = translate(proj,/* radians(sinusaid),*/ vec3(0.0f, 0.5f, 2.0f));

        //modele = rotate(modele, radians(sinusaid), vec3(0.0f, 0.0f, 0.0f));
        modele = translate(modele,/* radians(sinusaid),*/ vec3(0.0f, 0.5f, 5.0f));
        modele = rotate(modele, radians(sinusaid * 10), vec3(0.0f, 1.0f, 0.0f));
        //modele = scale(modele,vec3(1.0f,1.0f,1.0f));

        #pragma endregion excess
        //ViewMatrix.ViewMatrix1(Vector(0.0f, 1.0f, 0.0f),0,0,0, 1);
        //ViewMatrix.translete (Vector(0.0f, sinf(sinusaid), -2.0f));
        //ViewMatrix.set(2, 2, 10.0f);
        ViewMatrix.ViewMatrix1(Vector(0.0f, 0.5f /*sinf(sinusaid)*/, -5.0f), 0, 0,0,1.0f);
        
        
        //ViewMatrix.rotete(Vector(0, 1, 0), radians(sinusaid));
        vie = translate(vie, vec3(0.0f, -0.5f, -2.0f));
        vie = rotate(vie, radians(sinusaid) * 10, vec3(0.0f, 1.0f, 0.0f));
        //MATRIXprojectionMatrix.ViewMatrix1(Vector(0.0f, 0.5f, 2.0f), 0,0, 0, 1);
        MATRIXTrans.nulling();
        MATRIXTrans.translete(Vector(0.0f, 0.5f, 2.0f));

        MATRIXprojectionMatrixold.GenprojectionMatrix((float)(width / height), 90.0f, 0.1f, 100.0f);

        MATRIXprojectionMatrix.nultiply(MATRIXprojectionMatrixold , MATRIXTrans);


        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << proj[i][j] <<"(" + to_string(i) + "," + to_string(j) + ")   ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                
                cout << MATRIXprojectionMatrix.MAX[i][j] << "(" + to_string(i) + "," + to_string(j) + ")   ";
                

            }
            cout << endl;
        }
        
        

        
        
        const float vieMatrixConst[16] = {
        ViewMatrix.MAX[0][0],ViewMatrix.MAX[0][1],ViewMatrix.MAX[0][2],ViewMatrix.MAX[0][3],
        ViewMatrix.MAX[1][0],ViewMatrix.MAX[1][1],ViewMatrix.MAX[1][2],ViewMatrix.MAX[1][3],
        ViewMatrix.MAX[2][0],ViewMatrix.MAX[2][1],ViewMatrix.MAX[2][2],ViewMatrix.MAX[2][3],
        ViewMatrix.MAX[3][0],ViewMatrix.MAX[3][1],ViewMatrix.MAX[3][2],ViewMatrix.MAX[3][3] };

        

        const float projectionMatrix[16] = {
        MATRIXprojectionMatrix.MAX[0][0],MATRIXprojectionMatrix.MAX[0][1],MATRIXprojectionMatrix.MAX[0][2],MATRIXprojectionMatrix.MAX[0][3],
        MATRIXprojectionMatrix.MAX[1][0],MATRIXprojectionMatrix.MAX[1][1],MATRIXprojectionMatrix.MAX[1][2],MATRIXprojectionMatrix.MAX[1][3],
        MATRIXprojectionMatrix.MAX[2][0],MATRIXprojectionMatrix.MAX[2][1],MATRIXprojectionMatrix.MAX[2][2],MATRIXprojectionMatrix.MAX[2][3],
        MATRIXprojectionMatrix.MAX[3][0],MATRIXprojectionMatrix.MAX[3][1],MATRIXprojectionMatrix.MAX[3][2],MATRIXprojectionMatrix.MAX[3][3] };

        
        int modelL = glGetUniformLocation(shaderProgram.ID, "model");
        glUniformMatrix4fv(modelL, 1, GL_FALSE, vieMatrixConst/*glm::value_ptr(modele)*/);
        int project = glGetUniformLocation(shaderProgram.ID, "proj");
        glUniformMatrix4fv(project, 1, GL_FALSE, /*projectionMatrix*/ glm::value_ptr(proj));
        int viewL = glGetUniformLocation(shaderProgram.ID, "view");
        glUniformMatrix4fv(viewL, 1, GL_FALSE, glm::value_ptr(vie));
        /*
        cout << endl << "new" << endl;
        for (int i = 0; i < 16; i++) {
            
            cout << vieMatrixConst[i] << "     ";
            if ((i+1) % 4 == 0) {
                cout << endl;
            }
            
        }*/
        cout << endl <<"old" << endl;
        
        cout << endl;

        

        //cout << sizeof(modele) / sizeof(modele[0][0]) << endl;

        




        glUniform1f(unitID, 1.0f);
        glBindTexture(GL_TEXTURE_2D, texture);

        VAO1.Bind();

        
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(indices[0]), GL_UNSIGNED_INT,0);

        
        //glDepthMask(GL_FALSE);

        glfwSwapBuffers(window);

        
       
        glfwPollEvents();
        


        
        
    }
    

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();

    shaderProgram.Delete();

    glDeleteTextures(1, &texture);
    
   

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void vlaud() {

}




