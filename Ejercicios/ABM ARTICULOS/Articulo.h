#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

typedef struct
{
    int id;
    char articulo[128];
    float precio;
    int medida;
    int rubroId;

}Articulo;

typedef struct
{
    int id;
    char descripcion[51];

} Rubro;

Articulo* articulo_new();
Articulo* articulo_newParametros(char* idStr,char* articuloStr, char* precioStr, char* medidaStr, char* rubroIdStr);
void articulo_delete();

int articulo_setId(Articulo* this,int id);
int articulo_getId(Articulo* this,int* id);

int articulo_setArticulo(Articulo* this,char* articulo);
int articulo_getArticulo(Articulo* this,char* articulo);

int articulo_setPrecio(Articulo* this, float precio);
int articulo_getPrecio(Articulo* this, float* precio);

int articulo_setMedida(Articulo* this, int medida);
int articulo_getMedida(Articulo* this, int* medida);

int articulo_setRubroId(Articulo* this, int rubroId);
int articulo_getRubroId(Articulo* this, int* rubroId);

int cargarDescripcionRubro(char* descripcion, int idArt, Rubro* rubros);

void listArticulo(Articulo* articulo, Rubro* rubros);
int sortArticulos(void* articulo1,void* articulo2);

Articulo* aplicarDescuentos(void* art);

#endif // ARTICULO_H_INCLUDED




