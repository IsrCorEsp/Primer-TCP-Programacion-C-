# Mini-ERP — Soluciones S.A.

A console-based mini Enterprise Resource Planning (ERP) system developed in C++11 for a small family business. The system manages products, employees, clients, and sales, providing full CRUD operations, filters, statistics, and persistent JSON storage.

---

## Features

### Products
- Add, modify, and delete products
- Update stock
- Search by name (partial or full), category, or price range
- Filter products with critical stock
- Display the most and least expensive products

### Employees
- Add, modify, and delete employees
- Look up employee information
- Statistics: average salary, highest-paid employee, headcount by role

### Clients
- Add, modify, and delete clients *(clients with purchases cannot be deleted)*
- View full purchase history
- Filter clients by number of purchases or total amount spent
- Calculate total spent by a specific client

### Sales
- Register a sale: select client and products, stock updates automatically
- Delete a sale with optional stock restoration
- Filter sales by client or date (before, equal to, or after a given date)
- Statistics: total revenue by category, best-selling product, top client by purchases and by units bought

### General Statistics
- Total inventory cost: `C = Σ(stock × cost)`
- Average sales per client
- Average price per category
- Filter products by profit margin: `margin = price − cost`

---

## Class Structure

```
persona  (base class)
│── nombre, apellido, ID, telefono
│── getters / setters / mostrar()
│
├── empleado : persona
│   ── cargo, salario
│   ── mostrarEmp(), actualizarEmp()
│
└── cliente : persona
    ── correo, compras[]
    ── addCom(), eliminarCom(), historial()

Producto
── ID, nombre, categoria, precio, costo, stock
── getters / setters

ventas
── ID, cliente, dia, mes, year, productos[], total
── getters / setters
```

Inheritance is applied only in the `persona → empleado / cliente` hierarchy.

---

## Data Structures Used

| Structure | Usage |
|-----------|-------|
| `vector<Producto>` | Master product list |
| `vector<empleado>` | Master employee list |
| `vector<cliente>` | Master client list |
| `vector<ventas>` | Master sales list |
| `vector<string>` | Category registry |
| `map<string, int>` | Salary lookup, purchase count, stock lookup |
| `map<string, double>` | Total spent per client, profit margin per product |
| `map<string, Producto>` | Name-based product search and range filter |
| `map<string, vector<Producto>>` | Products grouped by category |
| `map<string, vector<ventas>>` | Sales grouped by client |
| `map<string, pair<string,int>>` | Client name + purchase/unit count |
| `map<string, pair<double,int>>` | Price sum + count per category, sales sum per client |
| `map<string, pair<int,double>>` | Units sold + revenue per category |
| `map<double, vector<string>>` | Products grouped by price |

---

## Business Rules

- A product cannot be sold if stock is insufficient
- A client cannot be deleted if they have registered purchases
- All calculations are performed inside dedicated functions, not in `main`
- Filters and statistics use vectors and maps

---

## JSON Persistence

Data is automatically loaded when the program starts and saved when it exits. It can also be saved manually at any time using the save option in the main menu. Four files are created in the same folder as the executable:

```
productos.json
empleados.json
clientes.json
ventas.json
```

JSON serialization is handled by [nlohmann/json](https://github.com/nlohmann/json) (single-header library).

**Example `productos.json`:**
```json
[
  {
    "ID": "P01",
    "nombre": "Laptop",
    "categoria": "Electronica",
    "precio": 1200.5,
    "costo": 800.0,
    "stock": 5
  }
]
```

---

## Requirements

- `g++` with C++11 support (GCC ≥ 4.8)
- [`json.hpp`](https://github.com/nlohmann/json/releases/download/v3.9.1/json.hpp) placed in the same folder as the source file (version 3.9.1, compatible with C++11)

---

## How to Build and Run

**1. Download `json.hpp`** (version 3.9.1) and place it in the same folder as `Primer_Parcial.cxx`.

**2. Compile:**
```bash
g++ -std=c++11 -O2 -o Primer_Parcial Primer_Parcial.cxx
```

**3. Run:**
```bash
./Primer_Parcial
```

**4. Save and Exit:** use the save option from the main menu to save at any time, or exit with option `0` to save automatically on close.

---

## Project Structure

```
project/
├── Primer_Parcial.cxx   # Full source code
├── json.hpp             # nlohmann/json v3.9.1 single-header library
├── README.md            # This file
├── productos.json       # Auto-generated on first exit
├── empleados.json
├── clientes.json
└── ventas.json
```

---

## Authors

Developed as part of the **first partial exam of the Programming subject** — Career: Telecommunications and Electronics Engineering.

1. Israel Córdova
2. Willian L. Rabeiro
3. Leyan Barrios
4. Alejandro L. Bencomo
5. Gabriel Fonte
6. Remberto Santalla
