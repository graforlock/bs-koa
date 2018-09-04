open Http;
open Koa;

let app = App.make ()

module ExampleMessages = {
  type dataT =
    | Data(string)
    | OrOthers;

  type data2T = string;

  type shared =
    | Message(dataT)
    | MessageOnEnter(data2T);

  type clientToServer =
    | Shared(shared)
    | Hi;

  type serverToClient = shared;
}

let http = Http.create(App.callback(app));

module MyServer = BsSocket.Server.Make(ExampleMessages);

let io = MyServer.createWithHttp(http);

MyServer.onConnect(
  io,
  socket => {
    open MyServer;
    print_endline("Got a connection!");
    let socket = Socket.join(socket, "someRoom");
    /* Polymorphic pipe which actually knows about ExampleCommon.t from InnerServer */
    Socket.on(
      socket,
      fun
      | Shared(message) => {
          Socket.broadcast(socket, message);
          Socket.emit(socket, message);
        }
      | Hi => {
          Js.log("oh, hi client.");
          Js.log(
            "Sorry I can't say hi back.  Try uncommenting the line below to see why.",
          );
          /* Socket.emit(socket, Hi); */
        },
    );
  },
);

Http.listen(http, 3000, () => print_endline("listening on *:3000"));
