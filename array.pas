program ArrayBasedList;

const
  MAX = 10;

type
  List = record
    data: array[1..MAX] of Integer;
    size: Integer;
  end;

// declare the variables
var
  L: List;
  i, pos, value: Integer;

procedure Initialize(var L: List);
begin
  L.size := 0;
end;

// insert
procedure Insert(var L: List; pos, value: Integer);
var
  i: Integer;
begin
  if L.size = MAX then
    writeln('List is full')
  else if (pos < 1) or (pos > L.size + 1) then
    writeln('Invalid position')
  else
  begin
    for i := L.size downto pos do
      L.data[i + 1] := L.data[i];
    L.data[pos] := value;
    L.size := L.size + 1;
  end;
end;

// delete
procedure Delete(var L: List; pos: Integer);
var
  i: Integer;
begin
  if (pos < 1) or (pos > L.size) then
    writeln('Invalid position')
  else
  begin
    for i := pos to L.size - 1 do
      L.data[i] := L.data[i + 1];
    L.size := L.size - 1;
  end;
end;

procedure Display(L: List);
var
  i: Integer;
begin
  if L.size = 0 then
    writeln('List is empty')
  else
    for i := 1 to L.size do
      write(L.data[i], ' ');
  writeln;
end;
// main program
begin
  Initialize(L);

  Insert(L, 1, 10);
  Insert(L, 2, 20);
  Insert(L, 3, 30);
  Display(L);

  Delete(L, 2);
  Display(L);
end.
