open Koa;

module Route = {
  type t;
  type options = array(Js.Dict.t(string));

  type middleware('a) = (App.ctx('a), string) => unit;

  [@bs.module] external route : t = "koa-route";
  [@bs.send] external all: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "all";
  [@bs.send] external get: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "get";
  [@bs.send] external post: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "post";
  [@bs.send] external put: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "put";
  [@bs.send] external head: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "head";
  [@bs.send] external del: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "del";
  [@bs.send] external delete: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "delete";
  [@bs.send] external options: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "options";
  [@bs.send] external trace: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "trace";
  [@bs.send] external copy: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "copy";
  [@bs.send] external lock: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "lock";
  [@bs.send] external mkcol: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "mkcol";
  [@bs.send] external move: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "move";
  [@bs.send] external purge: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "purge";
  [@bs.send] external propfind: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "propfind";
  [@bs.send] external proppatch: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "proppatch";
  [@bs.send] external unlock: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "unlock";
  [@bs.send] external report: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "report";
  [@bs.send] external mkactivity: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "mkactivity";
  [@bs.send] external checkout: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "checkout";
  [@bs.send] external merge: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "merge";
  [@bs.send] external mSearch: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "m-search";
  [@bs.send] external notify: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "notify";
  [@bs.send] external subscribe: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "subscribe";
  [@bs.send] external unsubscribe: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "unsubscribe";
  [@bs.send] external patch: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "patch";
  [@bs.send] external search: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "search";
  [@bs.send] external connect: (t, string, middleware('a), ~opts: options=?) => App.middleware('a) = "connect";
};