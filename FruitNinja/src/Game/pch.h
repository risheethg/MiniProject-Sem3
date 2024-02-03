#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include <chrono>
#include <thread>
#include <random>
#include <ctime>

#include "Log.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "stb_image.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <gtx/rotate_vector.hpp>
#include <gtx/euler_angles.hpp>
#include <gtx/rotate_normalized_axis.hpp>

const glm::vec3 g_CameraPos = glm::vec3(15.0f, 11.0f, 12.0f); //0.0f, 0.0f, 6.0f
const glm::vec3 g_CameraFront = glm::vec3(0.0f, 0.0f, -1.0f); //0.0f, 0.0f, -1.0f
const glm::vec3 g_CameraUp = glm::vec3(0.0f, 1.0f, 0.0f); // 0.0f,1.0f, 0.0f
 				
const glm::mat4 g_ProjectionMatrix = glm::perspective(glm::radians(90.0f), (float)1280 / (float)720, 1.0f, 100.0f); //glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, 0.01f, 100.0f);
const glm::mat4 g_ViewMatrix = glm::lookAt(g_CameraPos, g_CameraPos + g_CameraFront, g_CameraUp);