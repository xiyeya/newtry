
(cl:in-package :asdf)

(defsystem "trace-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "trace" :depends-on ("_package_trace"))
    (:file "_package_trace" :depends-on ("_package"))
  ))