

[OnPaint()와 OnEraseBkgnd() 처리 수정]
- CSCThemeDlg::OnPaint()에서 타이틀바를 그려줬으나 이 함수를 사용하면
  derived class의 OnPaint()에서 그림을 그려도 표시되지 않는다.
  일단 CSCThemeDlg::OnPaint()가 하던 일을 CSCThemeDlg::OnErageBkgnd()에서 하니
  derived class의 OnPaint()에서도 잘 그려지고 deactive 될 때 맨 위에 나타나는 흰색 띠를 없애기 위해
  derived class의 OnActivate()에서 timer를 사용하여 Invalidate() 했으나
  CSCThemeDlg::OnActivate()에서 Invalidate()을 호출하여 처리함.

