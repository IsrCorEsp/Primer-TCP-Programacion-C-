//Primer Parcial
//Integrantes:
//-Israel Cordova
//-Willian L. Rabeiro
//-Leyan Barrios
//-Alejandro L. Bencomo
//-Gabriel Fonte
//-Remberto Santalla


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include "json.hpp"
using namespace std;
using json=nlohmann::json;

class persona{
	protected:
	string nombre;
	string apellido;
	string ID;
	string phone;
	
	public:
	persona(string nom,string ap,string id,string tel){
		nombre=nom;
		apellido=ap;
		ID=id;
		phone= tel;
	}
	
	string getN(){
		return nombre;
	}
	string getA(){
		return apellido;
	}
	string getID(){
		return ID;
	}
	string getP(){
		return phone;
	}
	
	void setN(string nom1){
		nombre=nom1;
		cout<<"El nuevo nombre es:"<<nom1<<endl;
	}
	void setA(string ap1){
		apellido=ap1;
		cout<<"El nuevo apellido es:"<<ap1<<endl;
	}
	void setID(string id1){
		ID=id1;
		cout<<"El nuevo ID es:"<<id1<<endl;
	}
	void setP(string tel1){
		phone=tel1;
		cout<<"El nuevo telefono es:"<<tel1<<endl;
	}
	
	void mostrar(){
		cout<<"==============="<<endl;
		cout<<"Nombre:"<<nombre<<" "<<apellido<<endl;
		cout<<"ID:"<<ID<<endl;
		cout<<"Telefono:"<<phone<<endl;
		cout<<"==============="<<endl;
	}
};


class empleado : public persona{
	private:
	string cargo;
	int salario;
	
	public:	
	empleado (string nom,string ap,string id, string tel ,string car,int sal):persona(nom,ap,id,tel){
		cargo=car;
		if(sal>=1000){
			salario=sal;
		}else{
			salario=1000;
		}
	}

	string getC(){
		return cargo;
	}
	int getS(){
		return salario;
	}

	void setC(string car1){
		cargo=car1;
		cout<<"El nuevo cargo es:"<<car1<<endl;
	}
	 
	
	void mostrarEmp(){
		persona::mostrar();
		cout<<"Cargo: "<<cargo<<endl;
		cout<<"Salario: "<<salario<<endl;
	}
	
	void actualizarEmp(int sal1){
		if(sal1>=1000){
			salario=sal1;
		}
	}
};

void addEmp(vector<empleado>&em){
	string n,a,i,t,c;
	int s;
	cout<<"Nombre:"<<endl;
	cin>>n;
	cout<<"Apellido:"<<endl;
	cin>>a;
	cout<<"Telefono:"<<endl;
	cin>>t;
	cout<<"Cargo:"<<endl;
	cin>>c;
	cout<<"Salario: (minimo 1000, si se pone una cifra inferior a 1000, se pondra 1000 por defecto)"<<endl;
	cin>>s;
	int y;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<em.size();j++){
			if(em[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido, inserte otro difetente"<<endl;
		}
	}while(y!=1);
	empleado emp(n,a,i,t,c,s);
	em.push_back(emp);
	cout<<"Empleado añadido"<<endl;
}
void eliminarEmp(vector<empleado>&em){
	if(em.empty()){
		cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
	string i1;
	int x=0;
	cout<<"ID del empleado que desea eliminar:"<<endl;
	cin>>i1;
	for(int i=0;i<em.size();i++){
		if(em[i].getID()==i1){
			em.erase(em.begin() +i);
		cout<<"Empleado eliminado"<<endl;
			x=1;
			break;
		}
	}
	if(x==0){
		cout<<"Empleado no encontrado"<<endl;
	}
}
}


void modificarEmp(vector<empleado>&em){
		if(em.empty()){
		cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
	string i1,i,n,a,d,t,c;
	int x=0;
	int y;
	int s;
	cout<<"ID del empleado que desea modificar:"<<endl;
	cin>>i1;
	for(int j=0;j<em.size();j++){
		if(em[j].getID()==i1){
			cout<<"Nombre:"<<endl;
			cin>>n;
			cout<<"Apellido:"<<endl;
			cin>>a;
			cout<<"Telefono:"<<endl;
			cin>>t;
			cout<<"Cargo:"<<endl;
			cin>>c;
			cout<<"Salario: (minimo 1000, si se pone una cifra inferior a 1000, se pondra 1000 por defecto)"<<endl;
			cin>>s;
			do{
				y=1;
				cout<<"ID:"<<endl;
				cin>>i;
				for(int j=0;j<em.size();j++){
					if(em[j].getID()==i){
						if(i != i1){
						y=0;
					}
				}
				}
				if(y==0){
					cout<<"ID repetido, inserte otro diferente"<<endl;
				}
			}while(y!=1);		
			em[j].setN(n);
			em[j].setA(a);
			em[j].setID(i);
			em[j].setP(t);
			em[j].setC(c);
			em[j].actualizarEmp(s);
		cout<<"Empleado modificado"<<endl;
			x=1;	
		}
	}
	if(x==0){
		cout<<"Empleado no encontrado"<<endl;
	}
}
}

void consultarEmp(vector<empleado>&em){
	if(em.empty()){
		cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
	string i1;
	int x=0;
	cout<<"ID del empleado q desea consultar:"<<endl;
	cin>>i1;
	for(int i=0;i<em.size();i++){
		if(em[i].getID()==i1){
			em[i].mostrarEmp();
			x=1;
		}
	}
	if(x==0){
		cout<<"Empleado no encontrado"<<endl;
	}
}
}
void promedioEmp(vector<empleado>&em){
		if(em.empty()){
		cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
	double suma=0;
	if(em.empty()){
		cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
	for(int i=0;i<em.size();i++){
		suma+=em[i].getS();
	}
	cout<<"Promedio: "<<suma/em.size()<<endl;
	}
}
}
void listaEmp(vector<empleado>&em){
	if(em.empty()){
cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
cout<<"LISTA DE EMPLEADOS"<<endl;
	for(int i=0;i<(int)em.size();i++){
	cout<<"==============="<<endl;
		cout<<"Empleado "<<i+1<<":"<<endl;
		cout<<"ID: "<<em[i].getID()<<endl;
cout<<"Nombre: "<<em[i].getN()<<" "<<em[i].getA()<<endl;
	cout<<"Telefono: "<<em[i].getP()<<endl;
	cout<<"Cargo: "<<em[i].getC()<<endl;
cout<<"Salario: "<<em[i].getS()<<"$"<<endl;
		cout<<"==============="<<endl;
	}
	}
}


void mayorEmp(vector<empleado>&em){
	if(em.empty()){
cout<<"ERROR: No hay empleados registrados"<<endl;
	}else{
map<string,pair<string, int>> salMap;
for(int i=0;i<em.size();i++){
	salMap[em[i].getID()].first=em[i].getN();
	salMap[em[i].getID()].second=em[i].getS();
	  }
int max=0;
	for(auto &p:salMap){
	    if(p.second.second>max){ 
		max=p.second.second;
}
	}
	cout<<"Empleado/s con el mayor salario ("<<max<<"):"<<endl;
cout<<"==============="<<endl;
	for(auto &p:salMap){
if(p.second.second==max){ 
cout<<"Nombre: "<<p.second.first<<endl;
cout<<"ID: "<<p.first<<endl;
}
	}
cout<<"==============="<<endl;
}
}

void conteoEmp(vector<empleado>&em){
	if(em.empty()){
		cout<<"ERROR: No hay empleados añadidos"<<endl;
	}else{
		map<string,int> cargosMap;
		for(int i=0;i<em.size();i++){
			cargosMap[em[i].getC()]++;
		}
		cout<<"Cantidad de empleados por cargo:"<<endl;
		for(auto &p:cargosMap){
			cout<<"==============="<<endl;
			cout<<"Cargo: "<<p.first<<endl;
			cout<<"Cantidad: "<<p.second<<endl;
			cout<<"==============="<<endl;
		}
	}
}


class Producto {
	private :
	string ID;
	string nombre;
	string categoria;
	double precio, costo;
	int stock;
	
	public:
	
	
	 Producto(string id="", string n="", string c="", double p=0, double cos=0, int s=0) {
	 ID = id;
	 nombre = n;
	 categoria = c;
	 precio = p;
	 costo=cos;
	 stock = s;
	 }
	
	 
	 
	 int getStock(){
	 		return stock;
	 }
	 string getID(){
	 return ID;
	 }
	string getNombre(){
	return nombre;
	}
	string getCategoria(){
	return categoria;
	}
	double getPrecio(){
	 return precio;
	} 
	double getCosto(){
	 return costo;
	}
	 //setters
	 void setStock (int nuevoStock) {
	 			stock = nuevoStock;
	 			cout<<"Nuevo stock: "<<stock<<endl;
	 }
	 void setID (string nuevoID) {
	 			ID = nuevoID;
	 			cout<<"Nuevo ID: "<<ID<<endl;
	 }
	 void setNombre (string nuevoNombre) {
	 			nombre = nuevoNombre;
	 			cout<<"Nuevo nombre: "<<nombre<<endl;		
	 }
	 void setCateg (string nuevoCateg) {
	 			categoria= nuevoCateg;
	 			cout<<"Nueva categoria: "<<categoria<<endl;
	 }
	 void setPrecio (double nuevoPrecio) {
	 			precio = nuevoPrecio;
	 			cout<<"Nuevo precio: "<<precio<<endl;
	 }
	 void setCosto (double nuevoCosto) {
	 			costo = nuevoCosto;
	 			cout<<"Nuevo costo: "<<costo<<endl;
	 }
};

void upgStock(vector <Producto>&prod){
		if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	int s=0;
	int aux=0;
	string i1;
	cout<<"ID del producto que desea actualizar su stock:"<<endl;
	cin>>i1;
	for(int j=0;j<prod.size();j++){
		if(prod[j].getID()==i1){
			aux++;
		cout<<"Ingrese el nuevo stock"<<endl;
		cin>>s;
		if(s>0){
			prod[j].setStock(s);
		}else{
		cout<<"ERROR: Stock invalido"<<endl;
		}
		}
	}
	if(aux==0){
	 cout<<"No se encontro el producto"<<endl;
	}
	 }
}

void addProd(vector<Producto>&prod, vector<string>&categ) {
	string i,n,c;
	double p, cos;
	int s;
	int y=1;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<prod.size();j++){
			if(prod[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido, inserte otro diferente"<<endl;
		}
	}while(y!=1);
	cout<<"Nombre:"<<endl;
	cin>>n;
	cout<<"Categoria:"<<endl;
	cin>>c;
	do{
		y=1;
	cout<<"Costo:"<<endl;
	cin>>cos;
	if(cos<0){
		cout<<"ERROR: Costo invalido"<<endl;
		y=0;
	}
	}while(y==0);
	do{
		y=1;
	cout<<"Precio:"<<endl;
	cin>>p;
	if(p<0){
		cout<<"ERROR: Precio invalido"<<endl;
		y=0;
	}
	}while(y==0);
	y=1;
	do{
	cout<<"Stock:"<<endl;
	cin>>s;
	if(s<0){
		cout<<"ERROR: Stock invalido"<<endl;
		y=0;
	}
	}while(y==0);
	Producto prodaux(i, n, c, p, cos, s);
	prod.push_back(prodaux);
	cout<<"Producto añadido"<<endl;
	int cant=0;
	if(categ.empty()){
	categ.push_back(c);	
	}else{
		for(int i=0;i<categ.size();i++){
		if(categ[i]==c){
			cant++;
				}	
		}
		if(cant==0){
			categ.push_back(c);
		}
}
}

void eliminarProd(vector<Producto>&prod){
	 if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	 string i1;
	int x=0;
	cout<<"ID del producto que desea eliminar:"<<endl;
	cin>>i1;
	for(int i=0;i<prod.size();i++){
		if(prod[i].getID()==i1){
			prod.erase(prod.begin()+i);
		cout<<"Producto eliminado"<<endl;
			x=1;
			break;
		}
	}
	if(x==0){
		cout<<"Producto no encontrado"<<endl;
	}
}
}

void modificarProd(vector<Producto>&prod, vector<string>&categ){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	string i, n, c;
	double p, cos;
	int s;
	int x=0;
	int y;
	string i1;
	
	cout<<"ID del producto que desea modificar:"<<endl;
	cin>>i1;
	for(int j=0;j<prod.size();j++){
		if(prod[j].getID()==i1){
			cout<<"Nombre:"<<endl;
			cin>>n;
			cout<<"Categoria:"<<endl;
			cin>>c;
			cout<<"Costo:"<<endl;
			cin>>cos;
			cout<<"Precio:"<<endl;
			cin>>p;
			cout<<"Stock:"<<endl;
			cin>>s;
			do{
				y=1;
				cout<<"ID:"<<endl;
				cin>>i;
				for(int j=0;j<prod.size();j++){
					if(prod[j].getID()==i){
						if(i!=i1){
						y=0;
					}
				}
				}
				if(y==0){
					cout<<"ID repetido, inserte otro diferente"<<endl;
				}
			}while(y!=1);		
			prod[j].setNombre(n);
			prod[j].setCateg(c);
			prod[j].setID(i);
			prod[j].setPrecio(p);
			prod[j].setCosto(cos);
			prod[j].setStock(s);
		cout<<"Producto modificado"<<endl;
			x=1;	
			int cant=0;
	if(categ.empty()){
	categ.push_back(c);	
	}else{
		for(int i=0;i<categ.size();i++){
		if(categ[i]==c){
			cant++;
				}	
		}
		if(cant==0){
			categ.push_back(c);
		}
}
		}
	}
	if(x==0){
		cout<<"Producto no encontrado"<<endl;
	}
}
}

void listaProd(vector<Producto>&prod){
	if(prod.empty()){
cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
cout<<"LISTA DE PRODUCTOS"<<endl;
	for(int i=0;i<(int)prod.size();i++){
	cout<<"==============="<<endl;
		cout<<"Producto "<<i+1<<":"<<endl;
	cout<<"ID: "<<prod[i].getID()<<endl;
cout<<"Nombre: "<<prod[i].getNombre()<<endl;
	cout<<"Categoria: "<<prod[i].getCategoria()<<endl;
cout<<"Precio: "<<prod[i].getPrecio()<<"$"<<endl;
cout<<"Costo: "<<prod[i].getCosto()<<"$"<<endl;
cout<<"Stock: "<<prod[i].getStock()<<" unidades"<<endl;
		cout<<"==============="<<endl;
}
}
}



void stockcritico(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
		int cant=0;
		map<string, pair<string,int>> stockMap;
		for(int i=0;i<prod.size();i++){
			stockMap[prod[i].getID()].first=prod[i].getNombre();
			stockMap[prod[i].getID()].second=prod[i].getStock();
		}
		for(auto &p:stockMap){
			if(p.second.second<=10){
				cant++;
				cout<<"Productos con stock critico (10 unidades o menos): "<<endl;
	cout<<"==============="<<endl;
	cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
	cout<<"Stock: "<<p.second.second<<endl;
	cout<<"==============="<<endl;
			}
		}
		if(cant==0){
			cout<<"No hay productos con stock critico"<<endl;
		}
	}
}

void caro_barato(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
		double max=0;
		double min=prod[0].getPrecio();
		for(int i=0;i<prod.size();i++){
			if(prod[i].getPrecio()>max){ max=prod[i].getPrecio();
			}
			if(prod[i].getPrecio()<min){ min=prod[i].getPrecio();
			}
		}
map<string, pair<string, double>> carosMap;
map<string, pair<string, double>> baratosMap;
		for(int i=0;i<prod.size();i++){
			if(prod[i].getPrecio()==max){
carosMap[prod[i].getID()].first=prod[i].getNombre();
carosMap[prod[i].getID()].second=prod[i].getPrecio();
			}
			if(prod[i].getPrecio()==min){
baratosMap[prod[i].getID()].first=prod[i].getNombre();
baratosMap[prod[i].getID()].second=prod[i].getPrecio();
			}
		}
cout<<"Productos de mayor precio ("<<max<<"$): "<<endl;
		for(auto &p:carosMap){
		cout<<"==============="<<endl;
		cout<<"Nombre: "<<p.second.first<<endl;
		cout<<"ID: "<<p.first<<endl;
		cout<<"==============="<<endl;
		}
		cout<<""<<endl;
	cout<<"Productos de menor precio ("<<min<<"$): "<<endl;
		for(auto &p:baratosMap){
		cout<<"==============="<<endl;
	cout<<"Nombre: "<<p.second.first<<endl;
		cout<<"ID: "<<p.first<<endl;
		cout<<"==============="<<endl;
		}
	}
}

void rangoP (vector<Producto> &prod){
 if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
 cout<<"Ingrese primer limite"<<endl;
 double max;
 cin>>max;
cout<<"Ingrese segundo limite"<<endl;
 double min;
 cin>>min;
 if(min<0){
 	min=0;
 }
if(max<=min){
double temp=max;
max=min;
min=temp;
}
map<string,Producto> prodMap;
for(int i=0;i<prod.size();i++){
	prodMap[prod[i].getID()]=prod[i];
	}
cout<<"Productos en el rango:"<<endl;
int cant=0;
for(auto &p:prodMap){
if(p.second.getPrecio()<=max&&p.second.getPrecio()>=min){
	cout<<"==================="<<endl;
cout<<"Nombre: "<<p.second.getNombre()<<endl;
cout<<"ID: "<<p.first<<endl;
cout<<"Categoria: "<<p.second.getCategoria()<<endl;
cout<<"Precio: "<<p.second.getPrecio()<<endl;
cout<<"==================="<<endl;
	cant++;
	}
	}
if(cant==0){
cout<<"No se encontraron productos"<<endl;
}
}
}


void buscarCateg(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	cout<<"Ingrese la categoria"<<endl;
	string aux;
	int aux2=0;
	cin>>aux;
	map<string,vector<Producto>> categMap;
	for(int i=0;i<prod.size();i++){
		if(prod[i].getCategoria()==aux){
			aux2=1;
		categMap[prod[i].getCategoria()].push_back(prod[i]);
		}
	}
	if(aux2==1){
	cout<<"Productos de la categoria:"<<endl;
	for(auto &p:categMap){
	for(int i=0;i<p.second.size();i++){
		cout<<"==============="<<endl;  
cout<<"Nombre: "<<p.second[i].getNombre()<<endl;
cout<<"ID: "<<p.second[i].getID()<<endl;
cout<<"Precio: "<<p.second[i].getPrecio()<<endl;
	 cout<<"==============="<<endl;
		}
	}
	}else{
		cout<<"ERROR: No se encontraron productos de esa categoria"<<endl;		
	}
}
}


void buscarName (vector <Producto> &prod){
	cout<<"Ingrese el nombre del producto"<<endl;
	string aux;
	cin>>aux;
	map<string,Producto> prodMap;
for(int i=0;i<prod.size();i++){
	prodMap[prod[i].getID()]=prod[i];
	}
int cant=0;
cout<<"Productos encontrados: "<<endl;
	for(auto &p:prodMap){
	int pos=p.second.getNombre().find(aux);
		if(pos!=string::npos){
	cout<<"==============="<<endl;		
cout<<"Nombre: "<<p.second.getNombre()<<endl;
 cout<<"ID: "<<p.first<<endl;
cout<<"Categoria: "<<p.second.getCategoria()<<endl;
cout<<"Precio: "<<p.second.getPrecio()<<endl;
 	cout<<"==============="<<endl;
 	cant++;
	}
	}	
if(cant==0){
cout<<"No se encontraron productos"<<endl;
}
}

class cliente : public persona {
	private :
	string correo ;
	vector<string>compras;
	public:
	cliente(string nom,string ap,string id,string tel,string cor):persona (nom,ap,id,tel){
		correo=cor;
	}
	string getCor(){
		return correo;
	}
	vector<string> getCom(){
		return compras;
		}
	
	void setCor(string co){
		correo=co;
	}
	void addCom(string com){
		compras.push_back(com);
	}
	void eliminarCom(string id){
	for (int i=0;i<compras.size();i++){
		if(id==compras[i]){
			compras.erase(compras.begin()+i);
		}
			}	
	}
	void historial(){
		cout<<"historial de compras :"<<endl;
		for(int i=0;i<compras.size();i++){
			cout<<compras[i]<<endl;
		}
	}
};
void addCli(vector<cliente>&cl){
	string n,a,i,t,c;
	cout<<"Nombre:"<<endl;
	cin>>n;
	cout<<"Apellido:"<<endl;
	cin>>a;
	cout<<"Telefono:"<<endl;
	cin>>t;
	cout<<"Correo:"<<endl;
	cin>>c;
	int y;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<cl.size();j++){
			if(cl[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido, inserte otro diferente"<<endl;
		}
	}while(y!=1);
	cliente cli(n,a,i,t,c);
	cl.push_back(cli);
	cout<<"Cliente añadido"<<endl;
}
void eliminarCli(vector<cliente>&cl){
    if(cl.empty()){
cout<<"ERROR: No hay clientes registrados"<<endl;
	}else{
    string i1;
    int x=0;
    cout<<"ID del cliente que desea eliminar:"<<endl;
    cin>>i1;
    for(int i=0; i<cl.size(); i++){
        if(cl[i].getID()==i1){
            if(cl[i].getCom().empty()){
                cl.erase(cl.begin() + i);
           cout<<"Cliente eliminado"<<endl;
                x=1;
                break; 
            }else{
                cout<<"No se puede eliminar cliente con compras"<<endl;
                x=1;
                break; 
            }
        }
    }
    if(x==0){
        cout<<"Cliente no encontrado"<<endl;
    }
}
}

void modificarCli(vector<cliente>&cl){
	if(cl.empty()){
cout<<"ERROR: No hay clientes registrados"<<endl;
	}else{
	string i1,i,n,a,d,t,c;
	int x=0;
	int y;
	cout<<"ID del cliente que desea modificar:"<<endl;
	cin>>i1;
	for(int j=0;j<cl.size();j++){
		if(cl[j].getID()==i1){
			cout<<"Nombre:"<<endl;
			cin>>n;
			cout<<"Apellido:"<<endl;
			cin>>a;
			cout<<"Telefono:"<<endl;
			cin>>t;
			cout<<"Correo:"<<endl;
			cin>>c;
			do{
				y=1;
				cout<<"ID:"<<endl;
				cin>>i;
				for(int j=0;j<cl.size();j++){
					if(cl[j].getID()==i){
						if(i!=i1){
						y=0;
					}
				}
				}
				if(y==0){
					cout<<"ID repetido insertelo de nuevo"<<endl;
				}
			}while(y!=1);		
			cl[j].setN(n);
			cl[j].setA(a);
			cl[j].setID(i);
			cl[j].setP(t);
			cl[j].setCor(c);
			cout<<"Cliente modificado"<<endl;
			x=1;	
		}
	}
	if(x==0){
		cout<<"Cliente no encontrado"<<endl;
	}
}
}

void listaCli(vector<cliente>&cl){
	if(cl.empty()){
cout<<"ERROR: No hay clientes registrados"<<endl;
	}else{
	cout<<"LISTA DE CLIENTES"<<endl;
		for(int i=0;i<(int)cl.size();i++){
	cout<<"==============="<<endl;
		cout<<"Cliente "<<i+1<<":"<<endl;
cout<<"ID: "<<cl[i].getID()<<endl;
cout<<"Nombre: "<<cl[i].getN()<<" "<<cl[i].getA()<<endl;
	cout<<"Telefono: "<<cl[i].getP()<<endl;
cout<<"Correo: "<<cl[i].getCor()<<endl;
cout<<"Compras realizadas: "<<cl[i].getCom().size()<<endl;
		cout<<"==============="<<endl;
}
	}
}



void consultarHist(vector<cliente>&cl){
	string i1;
	int x=0;
	cout<<"ID del cliente q desea consultar:"<<endl;
	cin>>i1;
	for(int i=0;i<cl.size();i++){
		if(cl[i].getID()==i1){
			cl[i].historial();
			x=1;
		}
	}
	if(x==0){
		cout<<"Cliente no encontrado"<<endl;
	}
}


bool bisiesto(int a){
if ((a%4==0 && a%100!=0)||(a%400==0)){
	return 1;
		}else{
			return 0;
				}	
}
int cantD (int m, int a){
switch (m){
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
	return 31;
	case 4: case 6: case 9: case 11:
	return 30;
	case 2:
	if (bisiesto(a)){
	return 29;	
	}else{
	return 28;	
	}
	
}
}

bool valida(int d, int m, int a){
if ((d>=1 && d<=cantD(m, a))&&(m>=1 && m<=12)&&(a>=1)){
	return 1;
}else{
return 0;
}
}



class ventas{
	private :
	string ID;
	string cliente;
	int dia, mes, year;
	vector<Producto>productos;
	double total;
	
	public:
	
	
ventas(string id="", string c="", vector<Producto>p={}, double t=0, int d=1, int m=1, int a=1) {
	 ID = id;
	 cliente = c;
	 productos=p;
	 total=t;
	 dia=d;
	 mes=m;
	 year=a;
	 }
	
	 
	
	 string getID(){
	 return ID;
	 }
	string getCliente(){
	return cliente;
	}
	vector<Producto> getProd(){
	return productos;
	}
	double getTotal(){
	 return total;
	} 
	int getDia(){
		return dia;
	}
	int getMes(){
		return mes;
	}
	int getYear(){
		return year;
	}
	

	 void setID (string nuevoID) {
	 			ID = nuevoID;
	 			cout<<"Nuevo ID: "<<ID<<endl;
	 }
	 void setCliente (string nuevoCl) {
	 			cliente = nuevoCl;
	 			cout<<"Nuevo cliente: "<<cliente<<endl;		
	 }
	 void setTotal(double cantT){
	 	total=cantT;
	 		}
	 
	 void setDia(int d){
	 	dia=d;
	 	}
	 void setMes(int m){
	 	mes=m;
	 	}
	 void setYear(int a){
	 	year=a;;
	 	}			
};

void addVen(vector<ventas>&vent, vector<cliente>&cl, vector<Producto>&pr){
	if(cl.empty()){
	cout<<"ERROR: No hay clientes"<<endl;
	}else{
	string i, c, p1;
	vector<Producto>p;
	Producto p2;
	double t=0;
	int d, m, a;
	int s, in;
	int y;
	do{
		y=1;
		cout<<"ID:"<<endl;
		cin>>i;
		for(int j=0;j<vent.size();j++){
			if(vent[j].getID()==i){
			y=0;
			}
		}
		if(y==0){
			cout<<"ID repetido, inserte otrl diferente"<<endl;
		}
	}while(y!=1);
	cout<<"Cliente:"<<endl;
	cin>>c;
	int aux=0;
	for(int j=0;j<cl.size();j++){
	if(c==cl[j].getID()){
		aux=1;
		in=j;
	}	
	}
	if(aux!=0){
	int z=0;
	do{
		cout<<"Ingrese la fecha"<<endl;
		cout<<"Dia:"<<endl;
		cin>>d;
		cout<<"Mes:"<<endl;
		cin>>m;
		cout<<"Año:"<<endl;
		cin>>a;
		if(valida(d, m, a)){
			cout<<"Fecha valida"<<endl;
			z=1;
		}else{
		cout<<"ERROR: Fecha invalida"<<endl;
		}
		}while(z!=1);	
	z=0;
	do{
		cout<<"Ingrese el ID del producto que desea agregar"<<endl;
		cin>>p1;
		int auxc=0;
		for (int j=0;j<pr.size();j++){
	if(p1==pr[j].getID()){
		auxc=1;
		cout<<"Ingrese la cantidad"<<endl;
		cin>>s;
		if(s<=pr[j].getStock()&&s>0){
			string np=pr[j].getNombre();
			string cp=pr[j].getCategoria();
			double pp=pr[j].getPrecio();
			double pcos=pr[j].getCosto();
		Producto p2(p1,np,cp,pp,pcos,s);
	p.push_back(p2);
	t=t+pr[j].getPrecio()*s;
	pr[j].setStock(pr[j].getStock()-s);
	cout<<"Producto añadido"<<endl;
	}else{
		cout<<"Cantidad invalida"<<endl;
		}	
	}
		}
		if(auxc==0){
		cout<<"Producto no encontrado"<<endl;	
		}
		
	cout<<"Desea agregar otro producto (s/n)"<<endl;
	string o;
	int z1=0;
	do{
		cin>>o;
		if(o=="s"){
			z1=1;
		}
		if(o=="n"){
			z1=1;
			z=1;
		}
			
}while(z1!=1);		
}while(z!=1);
if(p.empty()){
	cout<<"Venta cancelada"<<endl;
}else{
ventas v(i,c,p,t,d,m,a);
vent.push_back(v);
cout<<"Venta añadida"<<endl;
cl[in].addCom(i);
}	
}else{
	cout<<"El cliente no existe"<<endl;
}
}
}

void eliminarVen(vector<ventas>&vent, vector<cliente>&cl,vector<Producto>&pr){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas"<<endl;
	}else{
	string i1;
	int x=0;
	cout<<"ID de la compra que desea eliminar:"<<endl;
	cin>>i1;
	for(int i=0;i<vent.size();i++){
		if(vent[i].getID()==i1){
		       int in=i;
	        for (int j=0;j<cl.size();j++){
	       if (vent[i].getCliente()==cl[j].getID()){
	        		cl[j].eliminarCom(i1);
	        		}	
	        }
			x=1;
			cout<<"Desea reestablecer el stock (s/n)"<<endl;
	string o;
	int z1=0;
	do{
		cin>>o;
		if(o=="s"){
			z1=1;
	for(int i=0;i<vent[in].getProd().size();i++){
		for(int k=0;k<pr.size();k++){
			if(pr[k].getID()==vent[in].getProd()[i].getID()){
			pr[k].setStock(pr[k].getStock()+vent[in].getProd()[i].getStock());	
			}
				}		
			}
		}
		if(o=="n"){
			z1=1;
			
		}
			
}while(z1!=1);
vent.erase(vent.begin() +i);		
cout<<"Venta eliminada"<<endl;	
		}
	}
	if(x==0){
		cout<<"Venta no encontrada"<<endl;
	}
}
}

void listaVent(vector<ventas>&vent){
	if(vent.empty()){
cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
	cout<<"LISTA DE VENTAS"<<endl;
	for(int i=0;i<(int)vent.size();i++){
	cout<<"==============="<<endl;
	cout<<"Venta "<<i+1<<":"<<endl;
		cout<<"ID: "<<vent[i].getID()<<endl;
	cout<<"Cliente: "<<vent[i].getCliente()<<endl;
	cout<<"Fecha: "<<vent[i].getDia()<<"/"<<vent[i].getMes()<<"/"<<vent[i].getYear()<<endl;
cout<<"Total: "<<vent[i].getTotal()<<"$"<<endl;
		cout<<"Productos:"<<endl;
for(int j=0;j<(int)vent[i].getProd().size();j++){
	cout<<"  - "<<vent[i].getProd()[j].getNombre();
cout<<" ("<<vent[i].getProd()[j].getStock()<<" unidades)"<<endl;
	}
	cout<<"==============="<<endl;
	}
}
}




void sbCliente(vector<ventas>&vent, vector<cliente>&cl){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas"<<endl;
	}else{
	string id;
	int aux=0;
	int aux2=0;
	cout<<"Ingrese el ID del cliente"<<endl;
	cin>>id;
	for(int i=0;i<cl.size();i++){
		if(cl[i].getID()==id){
			aux=1;
		}
	}
	if(aux==0){
		cout<<"El cliente no existe"<<endl;
	}else{
	map<string,vector<ventas>> ventMap;
	for(int i=0;i<vent.size();i++){
		if(vent[i].getCliente()==id){
		ventMap[vent[i].getCliente()].push_back(vent[i]);
		aux2=1;
		}
	}
	for(auto &p:ventMap){
	for(int i=0;i<p.second.size();i++){
			aux2=1;
	cout<<"==============="<<endl;
	cout<<"ID: "<<p.second[i].getID()<<endl;
cout<<"Productos:"<<endl;
for(int j=0;j<p.second[i].getProd().size();j++){
	cout<<p.second[i].getProd()[j].getNombre()<<"-"<<p.second[i].getProd()[j].getStock()<<" unidades"<<endl;
			  	}
cout<<"Total: "<<p.second[i].getTotal()<<endl;
cout<<"==============="<<endl;
		}
	}
	if(aux2==0){
		cout<<"El cliente no tiene compras"<<endl;
	}
}
}
}

void rangoFecha(vector<ventas>&vent){
	if(vent.empty()){
	cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
		int d1, m1, a1;
		int d2, m2, a2;
cout<<"Ingrese primera fecha:"<<endl;
	cout<<"Dia:"<<endl;
		cin>>d1;
	cout<<"Mes:"<<endl;
		cin>>m1;
	cout<<"Año:"<<endl;
		cin>>a1;
cout<<"Ingrese segunda fecha:"<<endl;
	cout<<"Dia:"<<endl;
		cin>>d2;
	cout<<"Mes:"<<endl;
		cin>>m2;
	cout<<"Año:"<<endl;
		cin>>a2;
		int temp;
		
		if(a1>a2){
		temp=a2;
		a2=a1;
		a1=temp;
		temp=d2;
		d2=d1;
		d1=temp;
		temp=m2;
		m2=m1;
		m1=temp;
		}
		if(a1==a2&&m1>m2){
		temp=d2;
		d2=d1;
		d1=temp;
		temp=m2;
		m2=m1;
		m1=temp;	
		}
		if(a1==a2&&m1==m2&&d1>d2){
		temp=d2;
		d2=d1;
		d1=temp;
		}		
	int cant=0;
	if(valida(d1,m1,a1) && valida(d2,m2,a2)){
		map<string,ventas> ventMap;
	for(int i=0;i<vent.size();i++){
		ventMap[vent[i].getID()]=vent[i];
			}
cout<<"Ventas en el rango de fechas:"<<endl;		
			for(auto &p:ventMap){
	int rangomin=0;
	if((p.second.getYear()>a1)||(p.second.getYear()==a1&&p.second.getMes()>m1)||(p.second.getYear()==a1&&p.second.getMes()==m1&&p.second.getDia()>=d1)){
		rangomin=1;
			}
		int rangomax=0;
	if((p.second.getYear()<a2)||(p.second.getYear()==a2&&p.second.getMes()<m2)||(p.second.getYear()==a2&&p.second.getMes()==m2&&p.second.getDia()<=d2)){
	     rangomax=1;
		}		
if(rangomin==1 && rangomax==1){
		cant++;
	cout<<"==============="<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"Cliente: "<<p.second.getCliente()<<endl;
cout<<"Fecha: "<<p.second.getDia()<<"/"<<p.second.getMes()<<"/"<<p.second.getYear()<<endl;
	cout<<"Productos:"<<endl;
for(int j=0;j<p.second.getProd().size();j++){
cout<<p.second.getProd()[j].getNombre()<<"-"<<p.second.getProd()[j].getStock()<<" unidades"<<endl;
					}
cout<<"Total: "<<p.second.getTotal()<<"$"<<endl;
	cout<<"==============="<<endl;
				}
}
			
  if(cant==0){
  	cout<<"No se encontraron ventas en ese rango"<<endl;
			}
		}else{
	cout<<"Rango de fechas invalido"<<endl;
	}
}
}



void totalCat(vector<ventas>&vent, vector<string>&categ){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
	map<string,pair<int,double>> totCatMap;
		for(int i=0;i<vent.size();i++){
 vector<Producto> prods=vent[i].getProd();
	for(int k=0;k<prods.size();k++){
	totCatMap[prods[k].getCategoria()].first+=prods[k].getStock();
 totCatMap[prods[k].getCategoria()].second+=prods[k].getPrecio()*prods[k].getStock();
			}
		}
		cout<<"Total vendido por categoria:"<<endl;
		for(auto &p:totCatMap){
	cout<<"==============="<<endl;
	cout<<"Categoria: "<<p.first<<endl;
cout<<"Cantidad vendida: "<<p.second.first<<endl;
	cout<<"Total dinero: "<<p.second.second<<"$"<<endl;
	cout<<"==============="<<endl;
}
	}
}


void masVendido(vector<ventas>&vent){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
	map<string,pair<string,int>> conteoMap;
		for(int i=0;i<vent.size();i++){
  vector<Producto> prods=vent[i].getProd();
		for(int j=0;j<prods.size();j++){
	conteoMap[prods[j].getID()].first=prods[j].getNombre();
conteoMap[prods[j].getID()].second+=prods[j].getStock();
		}
		}
		int max=0;	
	for(auto &p:conteoMap){
	if(p.second.second>max){
		max=p.second.second;
	}
		}
		cout<<"Producto/s mas vendido/s ("<<max<<" unidades):"<<endl;
	for(auto &p:conteoMap){
	if(p.second.second==max){
		cout<<"==============="<<endl;
	cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;	
		cout<<"==============="<<endl;
	}
		}
}
}


void clienteMas(vector<cliente>&cli, vector<ventas>&vent){
	if(vent.empty()){
		cout<<"No hay ventas registradas"<<endl;
	}else{
	map<string,pair<string,int>> comprasMap;
		for(int i=0;i<cli.size();i++){
comprasMap[cli[i].getID()].first=cli[i].getN();
comprasMap[cli[i].getID()].second=cli[i].getCom().size();
		}
		int max=0;
		for(auto &p:comprasMap){
if(p.second.second>max){
		 max=p.second.second;
}
		}
	cout<<"Clientes con mayor numero de compras("<<max<<"):"<<endl;
		for(auto &p:comprasMap){
				if(p.second.second==max){	
cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"==============="<<endl;
			}
		}
		map<string,pair<string,int>> prodMap;
		for(int i=0;i<cli.size();i++){
	prodMap[cli[i].getID()].first=cli[i].getN();
		prodMap[cli[i].getID()].second=0;
		}
	for(int i=0;i<vent.size();i++){
	int aux=0;
		for(auto &p:prodMap){
		if(p.first==vent[i].getCliente()){
			aux=1;
				}
			}
	if(aux==1){
	for(int j=0;j<vent[i].getProd().size();j++){
	prodMap[vent[i].getCliente()].second+=vent[i].getProd()[j].getStock();
		}
			}
		}
	max=0;
	for(auto &p:prodMap){
	if(p.second.second>max){ 
	max=p.second.second;
	}
		}
		cout<<""<<endl;
cout<<"Clientes con mayor numero de productos comprados("<<max<<"):"<<endl;
	for(auto &p:prodMap){
		if(p.second.second==max){
cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"==============="<<endl;
		}
	}
	}
}

void clientNumC(vector<cliente>&cl){
	if(cl.empty()){
		cout<<"ERROR: No hay clientes registrados"<<endl;
	}else{
		int num;
		int aux=0;
		cout<<"Ingrese el numero minimo de compras"<<endl;
		cin>>num;
map<string, pair<string, int>> comprasMap;
		for(int i=0;i<cl.size();i++){
			if(cl[i].getCom().size()>=num){
				aux=1;
	comprasMap[cl[i].getID()].first=cl[i].getN() +" "+ cl[i].getA() ;			
 comprasMap[cl[i].getID()].second=cl[i].getCom().size();
			}
		}
	cout<<"Clientes con "<<num<<" o mas compras:"<<endl;	
for(auto &p:comprasMap){
	cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
cout<<"ID: "<<p.first<<endl;
cout<<"Compras realizadas: "<<p.second.second<<endl;
cout<<"==============="<<endl;
	}
	if(aux==0){
cout<<"No se encontraron clientes con ese numero de compras"<<endl;
	}
	}
}


void buscarMonto(vector<ventas>&vent, vector<cliente>&cl){
	if(vent.empty()){
		cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
		double monto;
		int aux=0;
		cout<<"Ingrese el monto minimo gastado"<<endl;
		cin>>monto;
map<string, pair<string, double>> gastoMap;
		for(int i=0;i<vent.size();i++){
for(int k=0;k<cl.size();k++){
		if(cl[k].getID()==vent[i].getCliente()){
gastoMap[vent[i].getCliente()].first=cl[k].getN()+" "+cl[k].getA();
gastoMap[vent[i].getCliente()].second+=vent[i].getTotal();
		}
}
	}
	cout<<"Clientes que han gastado "<<monto<<"$ o mas:"<<endl;
	for(auto &p:gastoMap){
	if(p.second.second>=monto){
		aux=1;
	cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"Total gastado: "<<p.second.second<<"$"<<endl;
	cout<<"==============="<<endl;
			}
		}
		if(aux==0){
	cout<<"No se encontraron clientes con ese monto de compras"<<endl;
}
}
}



void totalGastado(vector<ventas>&vent, vector<cliente>&cl){
if(vent.empty()){
	cout<<"ERROR: No hay ventas registradas"<<endl;
	}else{
	string id;
	int aux=0;
	cout<<"Ingrese el ID del cliente"<<endl;
	cin>>id;
map<string, pair<string, double>> gastoMap;
	for(int i=0;i<vent.size();i++){
		if(id==vent[i].getCliente()){
		for(int k=0;k<cl.size();k++){
	if(cl[k].getID()==vent[i].getCliente()){
gastoMap[id].first=cl[k].getN()+" "+cl[k].getA();
gastoMap[id].second+=vent[i].getTotal();
			}
	}
		}
	}
for(auto &p:gastoMap){
			aux=1;
		cout<<"==============="<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
	cout<<"ID: "<<p.first<<endl;
cout<<"Total gastado: "<<p.second.second<<"$"<<endl;
	cout<<"==============="<<endl;
	}
	if(aux==0){
 cout<<"Cliente no encontrado"<<endl;
		}
	}
}



void costoInv(vector<Producto>&prod){
	if(prod.empty()){
		cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
		double total=0;
		for(int i=0;i<prod.size();i++){
			total+=prod[i].getCosto()*prod[i].getStock();
		}
		cout<<"==============="<<endl;
		cout<<"Costo total del inventario:"<<endl;
		cout<<total<<"$"<<endl;
		cout<<"==============="<<endl;
	}
}

void promVentCli(vector<ventas>&vent, vector<cliente>&cl){
	double prom, a, b;
	if(vent.empty()){
	cout<<"ERROR: No hay ventas registradas"<<endl;	
	}else{
		a=vent.size();
		b=cl.size();	
	prom=a/b;
	cout<<"Promedio de ventas por cliente: "<<prom<<" ventas"<<endl;
			}	
	}
	
void promCateg(vector<Producto>&prod, vector<string>&categ){
	if(prod.empty()){
cout<<"ERROR: No hay productos registrados"<<endl;
	}else{	
map<string,pair<double,int>> promCat;
	for(int j=0;j<prod.size();j++){
promCat[prod[j].getCategoria()].first+=prod[j].getPrecio();
promCat[prod[j].getCategoria()].second++;
		}
	cout<<"Promedio de precios por categoria:"<<endl;	
for(auto &p:promCat){
	cout<<"==============="<<endl;
	cout<<"Categoria: "<<p.first<<endl;
double promedio=p.second.first/p.second.second;
cout<<"Promedio: "<<promedio<<"$"<<endl;
	cout<<"==============="<<endl;
}
	}
}
	
	
	
void ganancia(vector<Producto>&prod){
if(prod.empty()){
	cout<<"ERROR: No hay productos registrados"<<endl;
	}else{
	double margenMin;
	int aux=0;
cout<<"Ingrese el margen de ganancia minimo"<<endl;
	cin>>margenMin;
 map<string, pair <string, double>> margenMap;
for(int i=0;i<prod.size();i++){
if(margenMin<=prod[i].getPrecio()-prod[i].getCosto()){	
margenMap[prod[i].getID()].first=prod[i].getNombre();
margenMap[prod[i].getID()].second=prod[i].getPrecio()-prod[i].getCosto();
}
		}
	cout<<"Productos con margen igual o superior a "<<margenMin<<"$:"<<endl;
	for(auto &p:margenMap){
cout<<"==============="<<endl;
cout<<"ID: "<<p.first<<endl;
cout<<"Nombre: "<<p.second.first<<endl;
cout<<"Margen de ganancia: "<<p.second.second<<"$"<<endl;
cout<<"==============="<<endl;
	aux=1;
	}
if(aux==0){
	cout<<"No se encontraron productos con ese margen de ganancia"<<endl;
		}			
	}
    }







void guardarProductos(vector<Producto>&prod){
    json arr=json::array();    
    for(int i=0;i<prod.size();i++){
        json obj;                       
        obj["ID"]=prod[i].getID();
        obj["nombre"]=prod[i].getNombre();
        obj["categoria"]=prod[i].getCategoria();
        obj["precio"]=prod[i].getPrecio();
        obj["costo"]=prod[i].getCosto();
        obj["stock"]=prod[i].getStock();
        arr.push_back(obj);            
    }
    ofstream file("productos.json");    
    file<<arr.dump(2);     
    file.close();
    cout<<"Productos guardados"<<endl;
}

void guardarEmpleados(vector<empleado>&em){
    json arr=json::array();
    for(int i=0;i<em.size();i++){
        json obj;
        obj["ID"]=em[i].getID();
        obj["nombre"]=em[i].getN();
        obj["apellido"]=em[i].getA();
        obj["telefono"]=em[i].getP();
        obj["cargo"]=em[i].getC();
        obj["salario"]=em[i].getS();
        arr.push_back(obj);
    }
    ofstream file("empleados.json");
    file<<arr.dump(2);
    file.close();
    cout<<"Empleados guardados"<<endl;
}

void guardarClientes(vector<cliente>&cl){
    json arr=json::array();
    for(int i=0;i<(int)cl.size();i++){
        json obj;
        obj["ID"]=cl[i].getID();
        obj["nombre"]=cl[i].getN();
        obj["apellido"]=cl[i].getA();
        obj["telefono"]=cl[i].getP();
        obj["correo"]=cl[i].getCor();
        json compras=json::array();  
        vector<string> coms=cl[i].getCom();
        for(int j=0;j<coms.size();j++){
            compras.push_back(coms[j]);  
        }
        obj["compras"]=compras;    
        arr.push_back(obj);
    }
    ofstream file("clientes.json");
    file<<arr.dump(2);
    file.close();
    cout<<"Clientes guardados"<<endl;
}

void guardarVentas(vector<ventas>&vent){
    json arr=json::array();
    for(int i=0;i<vent.size();i++){
        json obj;
        obj["ID"]=vent[i].getID();
        obj["cliente"]=vent[i].getCliente();
        obj["dia"]=vent[i].getDia();
        obj["mes"]=vent[i].getMes();
        obj["year"]=vent[i].getYear();
        obj["total"]=vent[i].getTotal();
        json prods=json::array();    
        vector<Producto> ps=vent[i].getProd();
        for(int j=0;j<ps.size();j++){
            json p;
            p["ID"]=ps[j].getID();
            p["nombre"]=ps[j].getNombre();
            p["categoria"]=ps[j].getCategoria();
            p["precio"]=ps[j].getPrecio();
            p["costo"]=ps[j].getCosto();
            p["stock"]=ps[j].getStock();
            prods.push_back(p);
        }
        obj["productos"]=prods;     
        arr.push_back(obj);
    }
    ofstream file("ventas.json");
    file<<arr.dump(2);
    file.close();
    cout<<"Ventas guardadas"<<endl;
}

void cargarProductos(vector<Producto>&prod, vector<string>&categ){
    ifstream file("productos.json");
    if(!file){ 
    return; 
    }                 
    json arr;
    file>>arr;                             
    file.close();
    for(int i=0;i<arr.size();i++){
        json &obj=arr[i];                 
        string id=obj["ID"];
        string nom=obj["nombre"];
        string cat=obj["categoria"];
        double pre=obj["precio"];
        double cos=obj["costo"];
        int stk=obj["stock"];
        Producto p(id,nom,cat,pre,cos,stk);
        prod.push_back(p);
        int y=1;                
        for(int j=0;j<categ.size();j++){
            if(categ[j]==cat) y=0;
        }
        if(y==1) categ.push_back(cat);
    }
    cout<<"Productos cargados: "<<prod.size()<<endl;
}

void cargarEmpleados(vector<empleado>&em){
    ifstream file("empleados.json");
    if(!file){
    	 return;
    }
    json arr;
    file>>arr;
    file.close();
    for(int i=0;i<arr.size();i++){
        json &obj = arr[i];
        string id  = obj["ID"];
        string nom = obj["nombre"];
        string ap  = obj["apellido"];
        string tel = obj["telefono"];
        string car = obj["cargo"];
        int sal    = obj["salario"];
        empleado e(nom,ap,id,tel,car,sal);
        em.push_back(e);
    }
    cout<<"Empleados cargados: "<<em.size()<<endl;
}

void cargarClientes(vector<cliente>&cl){
    ifstream file("clientes.json");
    if(!file){
    return;
    }
    json arr;
    file>>arr;
    file.close();
    for(int i=0;i<arr.size();i++){
        json &obj = arr[i];
        string id  = obj["ID"];
        string nom = obj["nombre"];
        string ap  = obj["apellido"];
        string tel = obj["telefono"];
        string cor = obj["correo"];
        cliente c(nom,ap,id,tel,cor);
     for(int j=0;j<obj["compras"].size();j++){
            string com = obj["compras"][j]; 
            c.addCom(com);           
        }
        cl.push_back(c);
    }
    cout<<"Clientes cargados: "<<cl.size()<<endl;
}

void cargarVentas(vector<ventas>&vent){
    ifstream file("ventas.json");
    if(!file){
    	return;
    }
    json arr;
    file>>arr;
    file.close();
    for(int i=0;i<arr.size();i++){
        json &obj=arr[i];
        string id=obj["ID"];
        string cli=obj["cliente"];
        int dia=obj["dia"];
        int mes=obj["mes"];
        int year=obj["year"];
        double tot=obj["total"];
        vector<Producto> prods;
 for(int j=0;j<obj["productos"].size();j++){
            json &p=obj["productos"][j]; 
            string pid=p["ID"];
            string pn=p["nombre"];
            string pc=p["categoria"];
            double pp=p["precio"];
            double pco=p["costo"];
            int ps=p["stock"];
            Producto prod(pid,pn,pc,pp,pco,ps);
            prods.push_back(prod);
        }
        ventas v(id,cli,prods,tot,dia,mes,year);
        vent.push_back(v);
    }
    cout<<"Ventas cargadas: "<<vent.size()<<endl;
}

int main(){
char op;
vector <empleado> empleados;
vector <Producto> productos;
vector <cliente> clientes;
vector <ventas> ventas;
vector<string> categorias;


cargarProductos(productos, categorias);
cargarEmpleados(empleados);
cargarClientes(clientes);
cargarVentas(ventas);

    
    
      
do{
  cout<<"========================================="<<endl;
  cout<<"MENU PRINCIPAL"<<endl;
  cout<<"Seleccione el numero de la opcion deseada"<<endl;
  cout<<"1- Gestion de productos"<<endl;
  cout<<"2- Gestion de empleados"<<endl;
  cout<<"3- Gestion de clientes"<<endl;
  cout<<"4- Gestion de ventas"<<endl;
  cout<<"5- Estadisticas"<<endl;
  cout<<"6- Guardar cambios"<<endl;
  cout<<"0- Salir"<<endl;
  cout<<"========================================="<<endl;
  cin>>op;
  system("cls");
  switch (op){
   case '1': {  
   char opProd;
    do{
  cout<<"========================================="<<endl;
     cout<<"GESTION DE PRODUCTOS"<<endl;
     cout<<"Seleccione el numero de la opcion deseada"<<endl;
     cout<<"1- Agregar producto"<<endl;
     cout<<"2- Eliminar producto"<<endl;
     cout<<"3- Modificar producto"<<endl;
     cout<<"4- Actualizar stock"<<endl;
     cout<<"5- Productos de stock critico"<<endl;
     cout<<"6- Productos de mayor y menor precio"<<endl;
      cout<<"7- Buscar producto"<<endl;
      cout<<"8- Lista de productos"<<endl;
      cout<<"0- Atras"<<endl;
cout<<"========================================="<<endl;
      cin>>opProd;
      system("cls");
   switch(opProd){
    case '1':
       addProd(productos, categorias);
       break;
     case '2':
    eliminarProd(productos);
      break;
    case '3':
   modificarProd(productos, categorias);
     break;
    case '4':
    upgStock(productos);
     break;
     case '5':
     stockcritico(productos);
      break;
    case '6':
    caro_barato(productos);
    break;
    case '7':{
    char opBP;
    do{
   cout<<"===================="<<endl;
     cout<<"Buscar producto por..."<<endl;
     cout<<"1- Nombre"<<endl;
     cout<<"2- Rango de precios"<<endl;
     cout<<"3- Categoria"<<endl;
     cout<<"0- Atras"<<endl;
  cout<<"===================="<<endl;
     cin>>opBP;
     system("cls");
     switch (opBP){
     	case '1':
     buscarName(productos);
      break;
  case '2':
    rangoP(productos);
      break;
    case '3':
    buscarCateg(productos);
    break;
    case '0':
    break;
    default:
     cout<<"Opcion invalida"<<endl;
     }
    }while(opBP!='0');
    break;
    }
    case '8':
    listaProd(productos);
    break;
   case '0':
    break;
   default:
    cout<<"Opcion invalida"<<endl;
       }
    }while(opProd!='0');
        break;
    }  
            
  case '2': { 
    char opEmp;
   do{
    cout<<"========================================="<<endl;
    cout<<"GESTION DE EMPLEADOS"<<endl;
    cout<<"Seleccione el numero de la opcion deseada"<<endl;
    cout<<"1- Agregar empleado"<<endl;
   cout<<"2- Eliminar empleado"<<endl;
  cout<<"3- Modificar empleado"<<endl;      
  cout<<"4- Consultar empleado"<<endl;
 cout<<"5- Promedio salarios"<<endl;
    cout<<"6- Mayor salario"<<endl;
    cout<<"7- Conteo por cargo"<<endl;
    cout<<"8- Lista de empleados"<<endl;
    cout<<"0- Atras"<<endl;
  cout<<"========================================="<<endl;
       cin>>opEmp;
          system("cls");          
     switch(opEmp){
      case '1':
         addEmp(empleados);
       break;
      case '2':
      eliminarEmp(empleados);
        break;
       case '3':
        modificarEmp(empleados);
        break;
       case '4':
      consultarEmp(empleados);        
      break;
      case '5':
       promedioEmp(empleados);
           break;
          case '6':
         mayorEmp(empleados);
       break;
       case '7':
       conteoEmp(empleados);
            break;
        case '8':
        listaEmp(empleados);
        break;
     case '0':
        break;
       default:
     cout<<"Opcion invalida"<<endl;
         }
      }while(opEmp!='0');
      break;
     }  
            
   case '3': {  
      char opCli;
      do{
   cout<<"========================================="<<endl;
         cout<<"GESTION DE CLIENTES"<<endl;
         cout<<"Seleccione el numero de la opcion deseada"<<endl;
         cout<<"1- Agregar cliente"<<endl;
         cout<<"2- Eliminar cliente"<<endl;
         cout<<"3- Modificar cliente"<<endl;
       cout<<"4- Consultar historial"<<endl;
       cout<<"5- Total gastado por cliente"<<endl;
cout<<"6- Buscar clientes por numero de compras"<<endl;
cout<<"7- Buscar clientes por total gastado"<<endl;
cout<<"8- Lista de clientes"<<endl;
       cout<<"0- Atras"<<endl;
cout<<"========================================="<<endl;
          cin>>opCli;   
          system("cls");      
         switch(opCli){
          case '1':
           addCli(clientes);
            break;
         case '2':
           eliminarCli(clientes);
          break;
       case '3':
         modificarCli(clientes);
         break;
        case '4':
       consultarHist(clientes);
         break;
         case '5':
         totalGastado(ventas, clientes);
         break;
         case '6':
         clientNumC(clientes);
         break;
         case '7':
         buscarMonto(ventas, clientes);
         break;
         case '8':
         listaCli(clientes);
         break;
      case '0':
       break;
       default:
       cout<<"Opcion invalida"<<endl;
       }
   }while(opCli!='0');
    break;
    }  
            
 case '4': {
     char opVen;
      do{
   cout<<"========================================="<<endl;
      cout<<"GESTION DE VENTAS"<<endl;
      cout<<"Seleccione el numero de la opcion deseada"<<endl;
      cout<<"1- Agregar venta"<<endl;
      cout<<"2- Eliminar venta"<<endl;
      cout<<"3- Buscar por cliente"<<endl;
      cout<<"4- Buscar por fecha"<<endl;
      cout<<"5- Total por categorias"<<endl;
   cout<<"6- Productos mas vendidos"<<endl;
cout<<"7- Clientes que mas compran"<<endl;
cout<<"8- Lista de Ventas"<<endl;       
         cout<<"0- Atras"<<endl;
cout<<"========================================="<<endl;
         cin>>opVen;
            system("cls");
       switch(opVen){
      case '1':
       addVen(ventas, clientes, productos);
              break;
       case '2':
     eliminarVen(ventas, clientes, productos);
               break;
           case '3':
        sbCliente(ventas, clientes);
             break;
          case '4':
        rangoFecha(ventas);           
        break;
        case '5':
       totalCat(ventas, categorias);
        break;
        case '6':
        masVendido(ventas);
        break;
        case '7':
        clienteMas(clientes, ventas);
        break;
        case '8':
        listaVent(ventas);
        break;
        case '0':
          break;
       default:
      cout<<"Opcion invalida"<<endl;
        }
      }while(opVen!='0');
      break;
         }
            
     case '5': {
       char opE;
       do{
cout<<"========================================="<<endl;
       	cout<<"ESTADISTICAS"<<endl;
       	cout<<"Seleccione el numero de la opcion deseada"<<endl;
  cout<<"1- Costo total de inventario"<<endl;
  cout<<"2- Promedio de ventas por clientes"<<endl;
  cout<<"3- Promedio de precios por categoria"<<endl;
  cout<<"4- Buscar producto segun margen de ganancia"<<endl;
  cout<<"0- Atras"<<endl;
cout<<"========================================="<<endl;
  cin>>opE;
  system("cls");
  switch(opE){         
          case '1':
          costoInv(productos);
            break;
            case '2':
            promVentCli(ventas, clientes);
              break;
              case '3':
              promCateg(productos, categorias);
                break;
                case '4':
                ganancia(productos);
                  break;
                  case '0':
                 break;
                 default:
                 cout<<"Opcion invalida"<<endl;
                 break;
            
  }
       }while(opE!='0');
            break;
          }
       case '6':
       guardarProductos(productos);
      guardarEmpleados(empleados);
      guardarClientes(clientes);
      guardarVentas(ventas);
cout<<"Cambios guardados con exito"<<endl;
        break;
         
       case '0':
    
      guardarProductos(productos);
      guardarEmpleados(empleados);
      guardarClientes(clientes);
      guardarVentas(ventas);
      cout<<"Cerrando el programa..."<<endl;
       break;
                
   default:
        cout<<"Opcion invalida"<<endl;
       }
    }while(op!='0');
    
    return 0;
}