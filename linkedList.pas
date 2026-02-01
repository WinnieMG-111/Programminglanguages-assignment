program LinkedList;

type
  NodePtr = ^Node; //pointer
  Node = record
    data: Integer;
    next: NodePtr;
  end;

var
  head, temp: NodePtr;

// insert at front
procedure InsertFront(var head: NodePtr; value: Integer);
var
  newNode: NodePtr;
begin
  new(newNode);
  newNode^.data := value;
  newNode^.next := head;
  head := newNode;
end;

// delete from front
procedure DeleteFront(var head: NodePtr);
var
  temp: NodePtr;
begin
  if head = nil then
    writeln('List is empty')
  else
  begin
    temp := head;
    head := head^.next;
    dispose(temp);  //free memory
  end;
end;

procedure Display(head: NodePtr);
begin
  if head = nil then
    writeln('List is empty')
  else
  begin
    while head <> nil do
    begin
      write(head^.data, ' -> ');
      head := head^.next;
    end;
    writeln('NULL');
  end;
end;

begin
  head := nil;

  InsertFront(head, 10);
  InsertFront(head, 20);
  InsertFront(head, 30);
  Display(head);

  DeleteFront(head);
  Display(head);
end.
