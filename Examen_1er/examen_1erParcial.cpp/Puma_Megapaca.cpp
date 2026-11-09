#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cmath>
using namespace std;

// =====================================================
// VARIABLES GLOBALES: INVENTARIO DE CADA PRODUCTO
// No se utilizan arreglos ni estructuras.
// =====================================================

int stock1 = 40, stock2 = 30, stock3 = 20;
int stock4 = 18, stock5 = 15, stock6 = 10;
int stock7 = 16, stock8 = 12, stock9 = 25;
int stock10 = 35, stock11 = 30, stock12 = 14;

// Unidades vendidas de cada producto
int vendido1 = 0, vendido2 = 0, vendido3 = 0;
int vendido4 = 0, vendido5 = 0, vendido6 = 0;
int vendido7 = 0, vendido8 = 0, vendido9 = 0;
int vendido10 = 0, vendido11 = 0, vendido12 = 0;

// Estadisticas generales
double gananciaCasual = 0, gananciaOficina = 0;
double gananciaCalzado = 0, gananciaAccesorios = 0;
double descuentosDia = 0, isvDia = 0, ventasDia = 0;

int pagosEfectivo = 0, pagosTransferencia = 0;
int numeroVentas = 0;

const double TASA_ISV = 0.15;
const double DOLAR = 26.42;

// =====================================================
// FUNCIONES DE ENTRADA
// =====================================================

int leerEntero(string mensaje) {
    int numero;

    while (true) {
        cout << mensaje;

        if (cin >> numero) {
            return numero;
        }

        cout << "Dato incorrecto. Ingrese un numero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double leerDecimal(string mensaje) {
    double numero;

    while (true) {
        cout << mensaje;

        if (cin >> numero) {
            return numero;
        }

        cout << "Dato incorrecto. Ingrese una cantidad numerica.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string leerTexto(string mensaje) {
    string texto;
    cout << mensaje;
    getline(cin >> ws, texto);
    return texto;
}

// =====================================================
// CATALOGO
// =====================================================

void mostrarProductos() {
    cout << "\n========== CATALOGO PUMA MEGAPACA ==========\n";
    cout << "CODIGO  PRODUCTO                 PRECIO       STOCK\n";
    cout << "1       Camiseta basica          L. 180.00    " << stock1 << endl;
    cout << "2       Jeans clasico            L. 450.00    " << stock2 << endl;
    cout << "3       Sudadera                 L. 520.00    " << stock3 << endl;
    cout << "4       Camisa formal            L. 650.00    " << stock4 << endl;
    cout << "5       Pantalon de vestir       L. 750.00    " << stock5 << endl;
    cout << "6       Blazer                   L. 1200.00   " << stock6 << endl;
    cout << "7       Tenis deportivos         L. 980.00    " << stock7 << endl;
    cout << "8       Zapatos formales         L. 1100.00   " << stock8 << endl;
    cout << "9       Sandalias                L. 420.00    " << stock9 << endl;
    cout << "10      Cinturon                 L. 220.00    " << stock10 << endl;
    cout << "11      Gorra                    L. 160.00    " << stock11 << endl;
    cout << "12      Bolso                    L. 850.00    " << stock12 << endl;
    cout << "0       Terminar compra\n";
}

// =====================================================
// TIPO DE CLIENTE Y DESCUENTOS
// =====================================================

int seleccionarCliente() {
    int tipo;

    cout << "\nTIPO DE CLIENTE\n";
    cout << "1. Regular: 5% en Ropa Casual\n";
    cout << "2. Premium: 10% en Calzado y Accesorios\n";
    cout << "3. Mayorista: 12% en Ropa de Oficina\n";

    do {
        tipo = leerEntero("Seleccione el tipo de cliente: ");
        if (tipo < 1 || tipo > 3) {
            cout << "Opcion no valida.\n";
        }
    } while (tipo < 1 || tipo > 3);

    return tipo;
}

// Devuelve la tasa de descuento por tipo de cliente.
// categoria: 1 Casual, 2 Oficina, 3 Calzado, 4 Accesorios.
double descuentoCliente(int tipo, int categoria) {
    double descuento = 0;

    switch (tipo) {
        case 1:
            if (categoria == 1) descuento = 0.05;
            break;
        case 2:
            if (categoria == 3 || categoria == 4) descuento = 0.10;
            break;
        case 3:
            if (categoria == 2) descuento = 0.12;
            break;
    }

    return descuento;
}

// Calcula el descuento de una linea de productos.
// Los descuentos y promociones aplicables se suman.
double calcularDescuento(double subtotal, double tasaCliente,
                         double tasaGenero, double tasaEdad,
                         double tasaPromocion, double tasaVolumen) {
    double tasaTotal = tasaCliente + tasaGenero + tasaEdad
                     + tasaPromocion + tasaVolumen;

    if (tasaTotal > 1.0) tasaTotal = 1.0;

    return subtotal * tasaTotal;
}

// =====================================================
// FUNCION PARA MOSTRAR UNA LINEA DE FACTURA
// =====================================================

void mostrarLinea(string nombre, int cantidad, double subtotal,
                  double descuento) {
    if (cantidad > 0) {
        cout << left << setw(25) << nombre
             << setw(8) << cantidad
             << setw(13) << fixed << setprecision(2) << subtotal
             << setw(13) << descuento << endl;
    }
}

// =====================================================
// METODO DE PAGO
// =====================================================

void procesarPago(double total) {
    int opcion;

    cout << "\nMETODO DE PAGO\n";
    cout << "1. Efectivo\n";
    cout << "2. Transferencia\n";

    do {
        opcion = leerEntero("Seleccione una opcion: ");
        if (opcion != 1 && opcion != 2) {
            cout << "Opcion incorrecta.\n";
        }
    } while (opcion != 1 && opcion != 2);

    switch (opcion) {
        case 1: {
            double recibido;

            do {
                recibido = leerDecimal("Dinero recibido: Lps. ");
                if (recibido < total) {
                    cout << "El monto no cubre el total de la factura.\n";
                }
            } while (recibido < total);

            cout << "Cambio: Lps. " << recibido - total << endl;
            pagosEfectivo++;
            break;
        }

        case 2: {
            string referencia, bancoEmision, bancoDestino;
            double transferido;

            referencia = leerTexto("Numero de comprobante/referencia: ");

            do {
                transferido = leerDecimal("Cantidad transferida exacta: Lps. ");
                if (fabs(transferido - total) > 0.01) {
                    cout << "Debe ingresar la cantidad exacta de la factura.\n";
                }
            } while (fabs(transferido - total) > 0.01);

            bancoEmision = leerTexto("Banco de emision: ");
            bancoDestino = leerTexto("Banco de destino: ");

            cout << "\nTransferencia registrada.\n";
            cout << "Referencia: " << referencia << endl;
            cout << "Banco de emision: " << bancoEmision << endl;
            cout << "Banco de destino: " << bancoDestino << endl;

            pagosTransferencia++;
            break;
        }
    }
}

// =====================================================
// PROCESAR UNA COMPRA
// =====================================================

void procesarCompra() {
    int tipo, genero, edad;
    int codigo, cantidad;
    char continuarProductos = 'S';

    // Cantidad comprada de cada producto en esta factura
    int c1=0, c2=0, c3=0, c4=0, c5=0, c6=0;
    int c7=0, c8=0, c9=0, c10=0, c11=0, c12=0;

    // Subtotales de cada producto
    double s1=0, s2=0, s3=0, s4=0, s5=0, s6=0;
    double s7=0, s8=0, s9=0, s10=0, s11=0, s12=0;

    // Descuentos de cada producto
    double d1=0, d2=0, d3=0, d4=0, d5=0, d6=0;
    double d7=0, d8=0, d9=0, d10=0, d11=0, d12=0;

    double subtotal = 0, descuentos = 0;
    double subtotalDescuento, impuesto, total;
    int puntos = 0;

    tipo = seleccionarCliente();

    cout << "\nGENERO\n1. Mujer\n2. Hombre\n3. Otro / No indicar\n";
    do {
        genero = leerEntero("Seleccione el genero: ");
        if (genero < 1 || genero > 3) cout << "Opcion incorrecta.\n";
    } while (genero < 1 || genero > 3);

    do {
        edad = leerEntero("Edad del cliente: ");
        if (edad < 1) cout << "Edad no valida.\n";
    } while (edad < 1);

    // Seleccion de productos: el inventario se valida antes de agregar.
    do {
        mostrarProductos();
        codigo = leerEntero("Ingrese el codigo del producto: ");

        if (codigo == 0) {
            continuarProductos = 'N';
        } else if (codigo < 1 || codigo > 12) {
            cout << "Codigo inexistente.\n";
        } else {
            cantidad = leerEntero("Cantidad que desea comprar: ");

            if (cantidad <= 0) {
                cout << "La cantidad debe ser mayor que cero.\n";
            } else {
                switch (codigo) {
                    case 1:
                        if (cantidad <= stock1 - c1) c1 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 2:
                        if (cantidad <= stock2 - c2) c2 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 3:
                        if (cantidad <= stock3 - c3) c3 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 4:
                        if (cantidad <= stock4 - c4) c4 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 5:
                        if (cantidad <= stock5 - c5) c5 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 6:
                        if (cantidad <= stock6 - c6) c6 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 7:
                        if (cantidad <= stock7 - c7) c7 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 8:
                        if (cantidad <= stock8 - c8) c8 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 9:
                        if (cantidad <= stock9 - c9) c9 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 10:
                        if (cantidad <= stock10 - c10) c10 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 11:
                        if (cantidad <= stock11 - c11) c11 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                    case 12:
                        if (cantidad <= stock12 - c12) c12 += cantidad;
                        else cout << "Stock insuficiente.\n";
                        break;
                }
            }
        }

        if (codigo != 0) {
            cout << "Desea agregar otro producto? (S/N): ";
            cin >> continuarProductos;
        }
    } while (continuarProductos == 'S' || continuarProductos == 's');

    // Subtotales
    s1=c1*180.0; s2=c2*450.0; s3=c3*520.0;
    s4=c4*650.0; s5=c5*750.0; s6=c6*1200.0;
    s7=c7*980.0; s8=c8*1100.0; s9=c9*420.0;
    s10=c10*220.0; s11=c11*160.0; s12=c12*850.0;

    subtotal = s1+s2+s3+s4+s5+s6+s7+s8+s9+s10+s11+s12;

    if (subtotal == 0) {
        cout << "\nNo se agregaron productos. No se genero factura.\n";
        return;
    }

    // Promociones que dependen de comprar dos productos especificos
    bool outfit = (c1 > 0 && c2 > 0);
    bool oficinaPro = (c4 > 0 && c5 > 0);

    // Tasas de descuentos adicionales por genero y edad
    double mujerAccesorios = (genero == 1) ? 0.08 : 0.0;
    double hombreCalzado = (genero == 2) ? 0.05 : 0.0;
    double terceraEdad = (edad >= 60) ? 0.10 : 0.0;

    // Descuentos por producto. Se suman cuando coinciden.
    d1=calcularDescuento(s1, descuentoCliente(tipo,1), 0, terceraEdad,
                         outfit ? 0.06 : 0, c1>3 ? 0.04 : 0);
    d2=calcularDescuento(s2, descuentoCliente(tipo,1), 0, terceraEdad,
                         outfit ? 0.06 : 0, c2>3 ? 0.04 : 0);
    d3=calcularDescuento(s3, descuentoCliente(tipo,1), 0, terceraEdad,
                         0, c3>3 ? 0.04 : 0);

    d4=calcularDescuento(s4, descuentoCliente(tipo,2), 0, terceraEdad,
                         oficinaPro ? 0.07 : 0, c4>3 ? 0.04 : 0);
    d5=calcularDescuento(s5, descuentoCliente(tipo,2), 0, terceraEdad,
                         oficinaPro ? 0.07 : 0, c5>3 ? 0.04 : 0);
    d6=calcularDescuento(s6, descuentoCliente(tipo,2), 0, terceraEdad,
                         0, c6>3 ? 0.04 : 0);

    d7=calcularDescuento(s7, descuentoCliente(tipo,3), hombreCalzado,
                         terceraEdad, 0, c7>3 ? 0.04 : 0);
    d8=calcularDescuento(s8, descuentoCliente(tipo,3), hombreCalzado,
                         terceraEdad, 0, c8>3 ? 0.04 : 0);
    d9=calcularDescuento(s9, descuentoCliente(tipo,3), hombreCalzado,
                         terceraEdad, 0, c9>3 ? 0.04 : 0);

    d10=calcularDescuento(s10, descuentoCliente(tipo,4), mujerAccesorios,
                          terceraEdad, 0, c10>3 ? 0.04 : 0);
    d11=calcularDescuento(s11, descuentoCliente(tipo,4), mujerAccesorios,
                          terceraEdad, 0, c11>3 ? 0.04 : 0);
    d12=calcularDescuento(s12, descuentoCliente(tipo,4), mujerAccesorios,
                          terceraEdad, 0, c12>3 ? 0.04 : 0);

    descuentos=d1+d2+d3+d4+d5+d6+d7+d8+d9+d10+d11+d12;

    subtotalDescuento = subtotal - descuentos;
    impuesto = subtotalDescuento * TASA_ISV;
    total = subtotalDescuento + impuesto;

    // Puntos por producto
    puntos = c1*10 + c2*25 + c3*30 + c4*40 + c5*45 + c6*70
           + c7*60 + c8*65 + c9*20 + c10*12 + c11*8 + c12*50;

    // Mostrar factura
    cout << "\n\n===============================================\n";
    cout << "          TIENDA DE ROPA PUMA MEGAPACA\n";
    cout << "                    FACTURA\n";
    cout << "===============================================\n";
    cout << left << setw(25) << "Producto" << setw(8) << "Cant."
         << setw(13) << "Subtotal" << setw(13) << "Descuento" << endl;

    mostrarLinea("Camiseta basica",c1,s1,d1);
    mostrarLinea("Jeans clasico",c2,s2,d2);
    mostrarLinea("Sudadera",c3,s3,d3);
    mostrarLinea("Camisa formal",c4,s4,d4);
    mostrarLinea("Pantalon de vestir",c5,s5,d5);
    mostrarLinea("Blazer",c6,s6,d6);
    mostrarLinea("Tenis deportivos",c7,s7,d7);
    mostrarLinea("Zapatos formales",c8,s8,d8);
    mostrarLinea("Sandalias",c9,s9,d9);
    mostrarLinea("Cinturon",c10,s10,d10);
    mostrarLinea("Gorra",c11,s11,d11);
    mostrarLinea("Bolso",c12,s12,d12);

    cout << "-----------------------------------------------\n";
    cout << "Subtotal:               Lps. " << subtotal << endl;
    cout << "Descuentos:             Lps. " << descuentos << endl;
    cout << "Subtotal con descuento: Lps. " << subtotalDescuento << endl;
    cout << "ISV (15%):              Lps. " << impuesto << endl;
    cout << "TOTAL A PAGAR:          Lps. " << total << endl;
    cout << "Total en dolares:       USD  " << total / DOLAR << endl;
    cout << "Puntos acumulados:           " << puntos << endl;
    cout << "===============================================\n";

    // Descontar inventario y actualizar unidades vendidas
    stock1-=c1; stock2-=c2; stock3-=c3; stock4-=c4;
    stock5-=c5; stock6-=c6; stock7-=c7; stock8-=c8;
    stock9-=c9; stock10-=c10; stock11-=c11; stock12-=c12;

    vendido1+=c1; vendido2+=c2; vendido3+=c3; vendido4+=c4;
    vendido5+=c5; vendido6+=c6; vendido7+=c7; vendido8+=c8;
    vendido9+=c9; vendido10+=c10; vendido11+=c11; vendido12+=c12;

    // Ganancia por categoria: subtotal menos descuentos, sin ISV.
    gananciaCasual += (s1-d1)+(s2-d2)+(s3-d3);
    gananciaOficina += (s4-d4)+(s5-d5)+(s6-d6);
    gananciaCalzado += (s7-d7)+(s8-d8)+(s9-d9);
    gananciaAccesorios += (s10-d10)+(s11-d11)+(s12-d12);

    descuentosDia += descuentos;
    isvDia += impuesto;
    ventasDia += total;
    numeroVentas++;

    procesarPago(total);
}

// =====================================================
// ESTADISTICAS
// =====================================================

void mostrarEstadisticas() {
    cout << "\n\n===============================================\n";
    cout << "          ESTADISTICAS DEL DIA\n";
    cout << "===============================================\n";

    if (numeroVentas == 0) {
        cout << "No se realizaron ventas.\n";
        return;
    }

    // Producto mas vendido: comparaciones individuales, sin arreglos.
    int mayor = vendido1;
    string nombreMayor = "Camiseta basica";

    if (vendido2 > mayor) { mayor=vendido2; nombreMayor="Jeans clasico"; }
    if (vendido3 > mayor) { mayor=vendido3; nombreMayor="Sudadera"; }
    if (vendido4 > mayor) { mayor=vendido4; nombreMayor="Camisa formal"; }
    if (vendido5 > mayor) { mayor=vendido5; nombreMayor="Pantalon de vestir"; }
    if (vendido6 > mayor) { mayor=vendido6; nombreMayor="Blazer"; }
    if (vendido7 > mayor) { mayor=vendido7; nombreMayor="Tenis deportivos"; }
    if (vendido8 > mayor) { mayor=vendido8; nombreMayor="Zapatos formales"; }
    if (vendido9 > mayor) { mayor=vendido9; nombreMayor="Sandalias"; }
    if (vendido10 > mayor) { mayor=vendido10; nombreMayor="Cinturon"; }
    if (vendido11 > mayor) { mayor=vendido11; nombreMayor="Gorra"; }
    if (vendido12 > mayor) { mayor=vendido12; nombreMayor="Bolso"; }

    // Menor vendido, considerando solo productos que tuvieron ventas.
    int menor = -1;
    string nombreMenor = "";

    if (vendido1 > 0) { menor=vendido1; nombreMenor="Camiseta basica"; }
    if (vendido2 > 0 && (menor==-1 || vendido2<menor)) { menor=vendido2; nombreMenor="Jeans clasico"; }
    if (vendido3 > 0 && (menor==-1 || vendido3<menor)) { menor=vendido3; nombreMenor="Sudadera"; }
    if (vendido4 > 0 && (menor==-1 || vendido4<menor)) { menor=vendido4; nombreMenor="Camisa formal"; }
    if (vendido5 > 0 && (menor==-1 || vendido5<menor)) { menor=vendido5; nombreMenor="Pantalon de vestir"; }
    if (vendido6 > 0 && (menor==-1 || vendido6<menor)) { menor=vendido6; nombreMenor="Blazer"; }
    if (vendido7 > 0 && (menor==-1 || vendido7<menor)) { menor=vendido7; nombreMenor="Tenis deportivos"; }
    if (vendido8 > 0 && (menor==-1 || vendido8<menor)) { menor=vendido8; nombreMenor="Zapatos formales"; }
    if (vendido9 > 0 && (menor==-1 || vendido9<menor)) { menor=vendido9; nombreMenor="Sandalias"; }
    if (vendido10 > 0 && (menor==-1 || vendido10<menor)) { menor=vendido10; nombreMenor="Cinturon"; }
    if (vendido11 > 0 && (menor==-1 || vendido11<menor)) { menor=vendido11; nombreMenor="Gorra"; }
    if (vendido12 > 0 && (menor==-1 || vendido12<menor)) { menor=vendido12; nombreMenor="Bolso"; }

    cout << "\nProducto mas vendido: " << nombreMayor
         << " (" << mayor << " unidades)\n";

    if (menor != -1) {
        cout << "Producto menos vendido: " << nombreMenor
             << " (" << menor << " unidades)\n";
    }

    cout << "\nGANANCIA POR CATEGORIA (SIN ISV)\n";
    cout << "Ropa Casual:      Lps. " << gananciaCasual << endl;
    cout << "Ropa de Oficina:  Lps. " << gananciaOficina << endl;
    cout << "Calzado:          Lps. " << gananciaCalzado << endl;
    cout << "Accesorios:       Lps. " << gananciaAccesorios << endl;

    cout << "\nTotal descuentos aplicados: Lps. " << descuentosDia << endl;
    cout << "Total ISV recaudado:        Lps. " << isvDia << endl;
    cout << "Total vendido en lempiras:  Lps. " << ventasDia << endl;
    cout << "Total vendido en dolares:   USD " << ventasDia/DOLAR << endl;

    cout << "\nMETODO DE PAGO MAS UTILIZADO\n";
    if (pagosEfectivo > pagosTransferencia) {
        cout << "Efectivo: " << pagosEfectivo << " ventas\n";
    } else if (pagosTransferencia > pagosEfectivo) {
        cout << "Transferencia: " << pagosTransferencia << " ventas\n";
    } else {
        cout << "Empate: efectivo " << pagosEfectivo
             << " y transferencia " << pagosTransferencia << endl;
    }

    cout << "Cantidad de ventas: " << numeroVentas << endl;
    cout << "===============================================\n";
}

// =====================================================
// MAIN
// =====================================================

int main() {
    char otroCliente;

    cout << fixed << setprecision(2);
    cout << "===============================================\n";
    cout << "       SISTEMA DE TIENDA PUMA MEGAPACA\n";
    cout << "===============================================\n";

    do {
        procesarCompra();

        cout << "\nDesea ingresar otro cliente? (S/N): ";
        cin >> otroCliente;

        while (otroCliente!='S' && otroCliente!='s' &&
               otroCliente!='N' && otroCliente!='n') {
            cout << "Ingrese S o N: ";
            cin >> otroCliente;
        }

    } while (otroCliente=='S' || otroCliente=='s');

    mostrarEstadisticas();

    cout << "\nGracias por utilizar el sistema.\n";
    return 0;
}
