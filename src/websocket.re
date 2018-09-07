open Koa;

module Socket = {
  type t('a) = App.t;

  type websocket('msg) = {.
    [@bs.meth] "send": 'msg => unit
  };

  type ctx('a, 'b) = App.ctx('a, websocket('b));
  type ws('a, 'b) = {. "ws": App.ctx('a, websocket('b)) };

  [@bs.module] external make: t('a) => ws('a, 'b) = "koa-websocket";
  [@bs.send] external use: ctx('a, 'b) => App.middleware('a, websocket('b)) => unit = "use"; 
  [@bs.send] external listen_ :
    ws('a, 'b) =>
    int =>
    string =>
    (Js.Null_undefined.t(Js.Exn.t) => unit) =>
    unit = "listen";

  let listen = (~port=3000, ~hostname="localhost", ~callback=(_) => (), app) =>
    listen_(app, port, hostname, callback);
};