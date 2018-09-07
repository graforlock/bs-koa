open Koa;

module Socket = {
  type t('a) = App.t;

  type websocket = {. [@bs.meth] "send": string => unit };

  type ctx('a) = App.ctx('a, websocket);
  type ws('a) = {. "ws": App.ctx('a, websocket) };

  [@bs.module] external make: t('a) => ws('a) = "koa-websocket";
  [@bs.send] external use: ctx('a) => App.middleware('a, websocket) => unit = "use"; 
  [@bs.send] external listen_ :
    ws('a) =>
    int =>
    string =>
    (Js.Null_undefined.t(Js.Exn.t) => unit) =>
    unit = "listen";

  let listen = (~port=3000, ~hostname="localhost", ~callback=(_) => (), app) =>
    listen_(app, port, hostname, callback);
};