#include<Color.h>

Color::Color() {};
Color::Color(float redVal, float greenVal, float blueVal, float alphaVal) {
    red = redVal / 255.0f;
    green = greenVal / 255.0f;
    blue = blueVal / 255.0f;
    alpha = alphaVal / 255.0f;
}