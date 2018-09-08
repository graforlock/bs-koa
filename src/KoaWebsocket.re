open Koa;

module Socket = {
  type websocket('msg) = {.
    [@bs.meth] "send": 'msg => unit,
    [@bs.meth] "on": string => ('msg => unit) => unit
  };

  type t('a, 'b) = App.t(App.ctx('a, websocket('b)));
  type ctx('a, 'b) = App.ctx('a, websocket('b));

  [@bs.module] external make: t('a, 'b) => t('a, 'b) = "koa-websocket";
  [@bs.send] external use: ctx('a, 'b) => App.middleware('a, websocket('b)) => unit = "use"; 
  
  let ws = app => make(app)##ws;
};