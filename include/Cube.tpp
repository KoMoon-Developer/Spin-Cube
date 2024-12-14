// Shape3D class

template <uint amount, uint vAmount>
void GL_COMPONENTS::CShape3D<amount, vAmount>::setFace(
    uint index, CB::vec3f pos, CB::vec3f data[vAmount]) {

  if (index >= amount) {
  cout << "Face Foi Modificada" << '\n';
    for (uint i = 0; i < vAmount; i++) {
      faces[0].vertex[i] = data[i];
      cout << faces[0].vertex[i].x << ',' << 
      faces[0].vertex[i].y << ',' << faces[0].vertex[i].z << '\n';
    }
    faces[0].facePos = pos;
  } else {
  cout << "Face Foi Modificada" << '\n';
    for (uint i = 0; i < vAmount; i++) {
      faces[index].vertex[i] = data[i];
      cout << faces[0].vertex[i].x << ',' << 
      faces[0].vertex[i].y << ',' << faces[0].vertex[i].z << '\n';
    }
    faces[index].facePos = pos;
  }

  setVertexs();

}
template <uint amount, uint vAmount>
float *GL_COMPONENTS::CShape3D<amount, vAmount>::getFace(uint index) {
  if (index >= amount)
    return vertexs[0];
  else 
    return vertexs[index];
}

template <uint amount, uint vAmount>
void GL_COMPONENTS::CShape3D<amount, vAmount>::setPos(uint index,
                                                      CB::vec3f pos) {
  if (index >= amount)
    faces[0].facePos = pos;
  else 
    faces[index].facePos = pos;
  setVertexs();
}

template <uint amount, uint vAmount>
void GL_COMPONENTS::CShape3D<amount, vAmount>::setVertexs() {
  uint xIndex;

  for (uint y = 0; y < amount; y++) {

  
    for (uint x = 0; x < vAmount; x++) {
      xIndex = x * 3;
      vertexs[y][xIndex] = faces[y].facePos.x + faces[y].vertex[x].x;
      vertexs[y][xIndex + 1] = faces[y].facePos.y + faces[y].vertex[x].y;
      vertexs[y][xIndex + 2] = faces[y].facePos.z + faces[y].vertex[x].z; 
      
    }
  }
}
