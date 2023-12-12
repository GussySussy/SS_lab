CREATE OR REPLACE TRIGGER last_modified_trigg
BEFORE INSERT OR UPDATE ON customers
FOR EACH ROW
BEGIN
    :NEW.last_modified := TO_CHAR(SYSDATE, 'DD-MM-YYYY HH24:MI:SS');
END;
/

DECLARE
    customer_row customers%ROWTYPE;

    CURSOR customer_cursor IS
        SELECT * FROM customers;

BEGIN
    OPEN customer_cursor;

    LOOP
        FETCH customer_cursor INTO customer_row;
        EXIT WHEN customer_cursor%NOTFOUND;

        DBMS_OUTPUT.PUT_LINE('CID: ' || customer_row.cid ||
                             ', Name: ' || customer_row.name ||
                             ', Phone: ' || customer_row.phone ||
                             ', Title: ' || customer_row.title ||
                             ', Salary: ' || customer_row.salary ||
                             ', Last Modified: ' || customer_row.last_modified);
    END LOOP;

    CLOSE customer_cursor;
END;
/

create or replace package customers_package is
  FUNCTION get_customer(cust_id customers.cid%type) RETURN customers%rowtype;
  PROCEDURE add_customer(new_cid customers.cid%type, new_name customers.name%type, new_phone customers.phone%type, new_title customers.title%type, new_salary customers.salary%type);
  END customers_package;
  /


create or replace package body customers_package
is
FUNCTION get_customer(cust_id customers.cid%TYPE)
    RETURN customers%ROWTYPE
    AS
    customers_row customers%rowtype;
    BEGIN
        select * into customers_row from customers where cid = cust_id;
        return customers_row;
    END get_customer;

PROCEDURE add_customer(new_cid customers.cid%type, new_name customers.name%type, new_phone customers.phone%type, new_title customers.title%type, new_salary customers.salary%type)
IS
BEGIN
INSERT INTO customers(cid, name, phone, title, salary)
VALUES (new_cid, new_name, new_phone, new_title, new_salary);
END add_customer;
END customers_package;
/

BEGIN
customers_package.add_customer(7,'Killua', 0128312098, 'Chief Assassin', 50000 );
end;
/