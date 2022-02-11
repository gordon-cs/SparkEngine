#pragma once

/* Represents a color in RGBA values */
struct Color {
    float red;
    float green;
    float blue;
    float alpha;
    Color();
    /* @param colorValues The color values in RGBA format */
    Color(float redVal, float greenVal, float blueVal, float alphaVal);
};