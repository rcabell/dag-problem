!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!
! is_dag
!
! Determines whether the given digraph is a dag
!
! Given a directed graph and the number of vertices in the graph, returns 1 if
! the digraph is a dag and 0 otherwise.
!
! The digraph is represented as an array of adjacency lists, and each adjacency
! list is stored as an int32_t that may be interpreted as a bit-array
! representation of an adjacency list, with a 1 in bit position i indicates
! that there is a directed edge to vertex i. Since each adjacency list (i.e.,
! each int32_t value of the array) can only represent out edges to vertices 0
! through 31, the digraph can have at most 32 vertices.
!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
integer(c_int) function is_dag(n_vertices, digraph) bind(C)

    use iso_c_binding, only : c_int32_t, c_int

    implicit none

    ! Arguments
    integer(c_int), intent(in), value :: n_vertices
    integer(c_int32_t), dimension(n_vertices), intent(in) :: digraph
    

    is_dag = 0

end function is_dag
