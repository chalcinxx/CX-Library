uniform sampler2D texture;
uniform float progress;

void main()
{
   vec2 uv = gl_TexCoord[0].xy;

   if (uv.x > progress)
      discard;

   gl_FragColor = texture2D(texture, uv);
}
