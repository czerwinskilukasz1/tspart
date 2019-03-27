#version 120

uniform sampler2D tex1;
uniform sampler2D tex2;
uniform float ratio;

void main()
{
  gl_FragColor = vec4(
    vec3(0.5)+(
      0.5*texture2D(tex1, gl_TexCoord[0].xy).rgb-
      0.5*texture2D(tex2, gl_TexCoord[0].xy).rgb
    ),
    1.0
  );
}
