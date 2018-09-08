open Koa;

module Route = {
  type t;
  type options = array(Js.Dict.t(string));

  type middleware('a, 'b) = (App.ctx('a, 'b), string) => unit;

  [@bs.module] external route : t = "koa-route";
  [@bs.send] external all: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "all";
  [@bs.send] external get: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "get";
  [@bs.send] external post: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "post";
  [@bs.send] external put: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "put";
  [@bs.send] external head: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "head";
  [@bs.send] external del: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "del";
  [@bs.send] external delete: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "delete";
  [@bs.send] external options: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "options";
  [@bs.send] external trace: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "trace";
  [@bs.send] external copy: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "copy";
  [@bs.send] external lock: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "lock";
  [@bs.send] external mkcol: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "mkcol";
  [@bs.send] external move: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "move";
  [@bs.send] external purge: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "purge";
  [@bs.send] external propfind: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "propfind";
  [@bs.send] external proppatch: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "proppatch";
  [@bs.send] external unlock: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "unlock";
  [@bs.send] external report: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "report";
  [@bs.send] external mkactivity: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "mkactivity";
  [@bs.send] external checkout: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "checkout";
  [@bs.send] external merge: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "merge";
  [@bs.send] external mSearch: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "m-search";
  [@bs.send] external notify: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "notify";
  [@bs.send] external subscribe: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "subscribe";
  [@bs.send] external unsubscribe: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "unsubscribe";
  [@bs.send] external patch: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "patch";
  [@bs.send] external search: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "search";
  [@bs.send] external connect: (t, string, middleware('a, 'b), ~opts: options=?) => App.middleware('a, 'b) = "connect";
};